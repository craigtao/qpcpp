//****************************************************************************
// Model: comp.qm
// File:  ./clock.cpp
//
// This code has been generated by QM tool (see state-machine.com/qm).
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//****************************************************************************
//${.::clock.cpp} ............................................................
#include "qpcpp.h"
#include "bsp.h"
#include "alarm.h"
#include "clock.h"

#include <stdio.h>

Q_DEFINE_THIS_FILE

// Active object class -------------------------------------------------------

#if ((QP_VERSION < 580) || (QP_VERSION != ((QP_RELEASE^4294967295) % 0x3E8)))
#error qpcpp version 5.8.0 or higher required
#endif

//${Components::AlarmClock} ..................................................
class AlarmClock : public QP::QActive {
private:
    uint32_t m_current_time;
    Alarm m_alarm;

public:
    QTimeEvt m_timeEvt;

public:
    AlarmClock();

protected:
    static QP::QState initial(AlarmClock * const me, QP::QEvt const * const e);
    static QP::QState timekeeping(AlarmClock * const me, QP::QEvt const * const e);
    static QP::QState mode24h(AlarmClock * const me, QP::QEvt const * const e);
    static QP::QState mode12h(AlarmClock * const me, QP::QEvt const * const e);
    static QP::QState final(AlarmClock * const me, QP::QEvt const * const e);
};


// Local objects -------------------------------------------------------------
static AlarmClock l_alarmClock; // the single instance of the AO

// Global-scope objects ------------------------------------------------------
QActive * const APP_alarmClock = &l_alarmClock; // "opaque" AO pointer

//............................................................................
//${Components::AlarmClock} ..................................................
//${Components::AlarmClock::AlarmClock} ......................................
AlarmClock::AlarmClock()
: QActive(Q_STATE_CAST(&AlarmClock::initial)),
  m_alarm(), // orthogonal component ctor
  m_timeEvt(this, TICK_SIG, 0U)
{}

//${Components::AlarmClock::SM} ..............................................
QP::QState AlarmClock::initial(AlarmClock * const me, QP::QEvt const * const e) {
    // ${Components::AlarmClock::SM::initial}
    (void)e; // unused parameter
    me->m_current_time = 0U;

    // (!) trigger the initial transition in the component
    me->m_alarm.init();
    return Q_TRAN(&timekeeping);
}
//${Components::AlarmClock::SM::timekeeping} .................................
QP::QState AlarmClock::timekeeping(AlarmClock * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        // ${Components::AlarmClock::SM::timekeeping}
        case Q_ENTRY_SIG: {
            // periodic timeout every second
            me->m_timeEvt.armX(BSP_TICKS_PER_SEC, BSP_TICKS_PER_SEC);
            status_ = Q_HANDLED();
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping}
        case Q_EXIT_SIG: {
            me->m_timeEvt.disarm();
            status_ = Q_HANDLED();
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::initial}
        case Q_INIT_SIG: {
            status_ = Q_TRAN(&mode24h);
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::CLOCK_24H}
        case CLOCK_24H_SIG: {
            status_ = Q_TRAN(&mode24h);
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::CLOCK_12H}
        case CLOCK_12H_SIG: {
            status_ = Q_TRAN(&mode12h);
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::ALARM}
        case ALARM_SIG: {
            BSP_showMsg("Wake up!!!");
            status_ = Q_HANDLED();
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::ALARM_SET, ALARM_ON, ALARM_OFF}
        case ALARM_SET_SIG: // intentionally fall through
        case ALARM_ON_SIG: // intentionally fall through
        case ALARM_OFF_SIG: {
            // (!) synchronously dispatch to the orthogonal component
            me->m_alarm.dispatch(e);
            status_ = Q_HANDLED();
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::TERMINATE}
        case TERMINATE_SIG: {
            BSP_showMsg("--> final");
            status_ = Q_TRAN(&final);
            break;
        }
        default: {
            status_ = Q_SUPER(&top);
            break;
        }
    }
    return status_;
}
//${Components::AlarmClock::SM::timekeeping::mode24h} ........................
QP::QState AlarmClock::mode24h(AlarmClock * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        // ${Components::AlarmClock::SM::timekeeping::mode24h}
        case Q_ENTRY_SIG: {
            BSP_showMsg("*** 24-hour mode");
            status_ = Q_HANDLED();
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::mode24h::TICK}
        case TICK_SIG: {
            // roll over in 24-hr mode?
            if (++me->m_current_time == 24U*60U) {
                me->m_current_time = 0U;
            }
            BSP_showTime24H("", me->m_current_time, 60U);

            TimeEvt pe; // temporary synchronous event for the component
            pe.sig = TIME_SIG;
            pe.current_time = me->m_current_time;

            // (!) synchronously dispatch to the orthogonal component
            me->m_alarm.dispatch(&pe);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&timekeeping);
            break;
        }
    }
    return status_;
}
//${Components::AlarmClock::SM::timekeeping::mode12h} ........................
QP::QState AlarmClock::mode12h(AlarmClock * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        // ${Components::AlarmClock::SM::timekeeping::mode12h}
        case Q_ENTRY_SIG: {
            BSP_showMsg("*** 12-hour mode");
            status_ = Q_HANDLED();
            break;
        }
        // ${Components::AlarmClock::SM::timekeeping::mode12h::TICK}
        case TICK_SIG: {
            // roll over in 12-hr mode?
            if (++me->m_current_time == 12U*60U) {
                me->m_current_time = 0U;
            }
            BSP_showTime12H("", me->m_current_time, 60U);

            TimeEvt pe; // temporary synchronous event for the component
            pe.sig = TIME_SIG;
            pe.current_time = me->m_current_time;

            // (!) synchronously dispatch to the orthogonal component
            me->m_alarm.dispatch(&pe);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&timekeeping);
            break;
        }
    }
    return status_;
}
//${Components::AlarmClock::SM::final} .......................................
QP::QState AlarmClock::final(AlarmClock * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        // ${Components::AlarmClock::SM::final}
        case Q_ENTRY_SIG: {
            BSP_showMsg("Bye! Bye!");
            QF::stop(); // terminate the application
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&top);
            break;
        }
    }
    return status_;
}


//****************************************************************************
// Model: history.qm
// File:  ./history.cpp
//
// This code has been generated by QM tool (see state-machine.com/qm).
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This code is covered by the following commercial QP license:
// License #   : QPCPP-EVAL-161130
// Issued to   : Company/individual evaluating the QP/C++ framework
// Framework(s): qpcpp
// Support ends: 2017-01-31
// Product(s)  :
// This license is available only for evaluation purposes and
// the generated code is still licensed under the terms of GPL.
// Please submit request for extension of the evaluaion period at:
// http://www.state-machine.com/licensing/index.html#RequestForm
//****************************************************************************
//${.::history.cpp} ..........................................................
#include "qep_port.h"
#include "qassert.h"
#include "history.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Q_DEFINE_THIS_FILE


#if ((QP_VERSION < 580) || (QP_VERSION != ((QP_RELEASE^4294967295) % 0x3E8)))
#error qpcpp version 5.8.0 or higher required
#endif

//${SMs::ToastOven} ..........................................................
class ToastOven : public QP::QMsm {
public:
    ToastOven();

protected:
    static QP::QState initial(ToastOven * const me, QP::QEvt const * const e);
    static QP::QState doorClosed  (ToastOven * const me, QP::QEvt const * const e);
    static QP::QState doorClosed_e(ToastOven * const me);
    static QP::QState doorClosed_x(ToastOven * const me);
    static QP::QState doorClosed_i(ToastOven * const me);
    static QP::QMState const doorClosed_s;
    static QP::QState heating  (ToastOven * const me, QP::QEvt const * const e);
    static QP::QState heating_e(ToastOven * const me);
    static QP::QState heating_x(ToastOven * const me);
    static QP::QState heating_i(ToastOven * const me);
    static QP::QMState const heating_s;
    static QP::QState toasting  (ToastOven * const me, QP::QEvt const * const e);
    static QP::QState toasting_e(ToastOven * const me);
    static QP::QMState const toasting_s;
    static QP::QState baking  (ToastOven * const me, QP::QEvt const * const e);
    static QP::QState baking_e(ToastOven * const me);
    static QP::QMState const baking_s;
    static QP::QState off  (ToastOven * const me, QP::QEvt const * const e);
    static QP::QState off_e(ToastOven * const me);
    static QP::QMState const off_s;
    static QP::QState doorOpen  (ToastOven * const me, QP::QEvt const * const e);
    static QP::QState doorOpen_e(ToastOven * const me);
    static QP::QState doorOpen_x(ToastOven * const me);
    static QP::QMState const doorOpen_s;
    static QP::QState final  (ToastOven * const me, QP::QEvt const * const e);
    static QP::QState final_e(ToastOven * const me);
    static QP::QMState const final_s;

protected:
    QP::QMState const *his_doorClosed;
};


static ToastOven l_oven; // the only instance of the ToastOven class

// global-scope definitions ------------------------------------
QP::QMsm * const the_oven = &l_oven; // the opaque pointer

//${SMs::ToastOven} ..........................................................
//${SMs::ToastOven::ToastOven} ...............................................
ToastOven::ToastOven()
 : QMsm(Q_STATE_CAST(&ToastOven::initial))
{}

//${SMs::ToastOven::SM} ......................................................
QP::QState ToastOven::initial(ToastOven * const me, QP::QEvt const * const e) {
    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[3];
    } const tatbl_ = { // transition-action table
        &doorClosed_s, // target state
        {
            Q_ACTION_CAST(&doorClosed_e), // entry
            Q_ACTION_CAST(&doorClosed_i), // initial tran.
            Q_ACTION_CAST(0) // zero terminator
        }
    };
    // ${SMs::ToastOven::SM::initial}
    (void)e; /* avoid compiler warning */
    // state history attributes
    me->his_doorClosed = &off_s;
    return QM_TRAN_INIT(&tatbl_);
}
//${SMs::ToastOven::SM::doorClosed} ..........................................
QP::QMState const ToastOven::doorClosed_s = {
    static_cast<QP::QMState const *>(0), // superstate (top)
    Q_STATE_CAST(&ToastOven::doorClosed),
    Q_ACTION_CAST(&ToastOven::doorClosed_e),
    Q_ACTION_CAST(&ToastOven::doorClosed_x),
    Q_ACTION_CAST(&ToastOven::doorClosed_i)
};
// ${SMs::ToastOven::SM::doorClosed}
QP::QState ToastOven::doorClosed_e(ToastOven * const me) {
    printf("door-Closed;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_ENTRY(&doorClosed_s);
}
// ${SMs::ToastOven::SM::doorClosed}
QP::QState ToastOven::doorClosed_x(ToastOven * const me) {
    // save deep history
    me->his_doorClosed = me->stateObj();
    return QM_EXIT(&doorClosed_s);
}
// ${SMs::ToastOven::SM::doorClosed::initial}
QP::QState ToastOven::doorClosed_i(ToastOven * const me) {
    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // transition-action table
        &off_s, // target state
        {
            Q_ACTION_CAST(&off_e), // entry
            Q_ACTION_CAST(0) // zero terminator
        }
    };
    // ${SMs::ToastOven::SM::doorClosed::initial}
    return QM_TRAN_INIT(&tatbl_);
}
// ${SMs::ToastOven::SM::doorClosed}
QP::QState ToastOven::doorClosed(ToastOven * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        // ${SMs::ToastOven::SM::doorClosed::TERMINATE}
        case TERMINATE_SIG: {
            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // transition-action table
                &final_s, // target state
                {
                    Q_ACTION_CAST(&doorClosed_x), // exit
                    Q_ACTION_CAST(&final_e), // entry
                    Q_ACTION_CAST(0) // zero terminator
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        // ${SMs::ToastOven::SM::doorClosed::OPEN}
        case OPEN_SIG: {
            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // transition-action table
                &doorOpen_s, // target state
                {
                    Q_ACTION_CAST(&doorClosed_x), // exit
                    Q_ACTION_CAST(&doorOpen_e), // entry
                    Q_ACTION_CAST(0) // zero terminator
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        // ${SMs::ToastOven::SM::doorClosed::TOAST}
        case TOAST_SIG: {
            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // transition-action table
                &toasting_s, // target state
                {
                    Q_ACTION_CAST(&heating_e), // entry
                    Q_ACTION_CAST(&toasting_e), // entry
                    Q_ACTION_CAST(0) // zero terminator
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        // ${SMs::ToastOven::SM::doorClosed::BAKE}
        case BAKE_SIG: {
            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // transition-action table
                &baking_s, // target state
                {
                    Q_ACTION_CAST(&heating_e), // entry
                    Q_ACTION_CAST(&baking_e), // entry
                    Q_ACTION_CAST(0) // zero terminator
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        // ${SMs::ToastOven::SM::doorClosed::OFF}
        case OFF_SIG: {
            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[2];
            } const tatbl_ = { // transition-action table
                &off_s, // target state
                {
                    Q_ACTION_CAST(&off_e), // entry
                    Q_ACTION_CAST(0) // zero terminator
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
//${SMs::ToastOven::SM::doorClosed::heating} .................................
QP::QMState const ToastOven::heating_s = {
    &ToastOven::doorClosed_s, // superstate
    Q_STATE_CAST(&ToastOven::heating),
    Q_ACTION_CAST(&ToastOven::heating_e),
    Q_ACTION_CAST(&ToastOven::heating_x),
    Q_ACTION_CAST(&ToastOven::heating_i)
};
// ${SMs::ToastOven::SM::doorClosed::heating}
QP::QState ToastOven::heating_e(ToastOven * const me) {
    printf("heater-On;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_ENTRY(&heating_s);
}
// ${SMs::ToastOven::SM::doorClosed::heating}
QP::QState ToastOven::heating_x(ToastOven * const me) {
    printf("heater-Off;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_EXIT(&heating_s);
}
// ${SMs::ToastOven::SM::doorClosed::heating::initial}
QP::QState ToastOven::heating_i(ToastOven * const me) {
    static struct {
        QP::QMState const *target;
        QP::QActionHandler act[2];
    } const tatbl_ = { // transition-action table
        &toasting_s, // target state
        {
            Q_ACTION_CAST(&toasting_e), // entry
            Q_ACTION_CAST(0) // zero terminator
        }
    };
    // ${SMs::ToastOven::SM::doorClosed::heating::initial}
    return QM_TRAN_INIT(&tatbl_);
}
// ${SMs::ToastOven::SM::doorClosed::heating}
QP::QState ToastOven::heating(ToastOven * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; // avoid compiler warning in case 'me' is not used
    return status_;
}
//${SMs::ToastOven::SM::doorClosed::heating::toasting} .......................
QP::QMState const ToastOven::toasting_s = {
    &ToastOven::heating_s, // superstate
    Q_STATE_CAST(&ToastOven::toasting),
    Q_ACTION_CAST(&ToastOven::toasting_e),
    Q_ACTION_CAST(0), // no exit action
    Q_ACTION_CAST(0)  // no intitial tran.
};
// ${SMs::ToastOven::SM::doorClosed::heating::toasting}
QP::QState ToastOven::toasting_e(ToastOven * const me) {
    printf("toasting;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_ENTRY(&toasting_s);
}
// ${SMs::ToastOven::SM::doorClosed::heating::toasting}
QP::QState ToastOven::toasting(ToastOven * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; // avoid compiler warning in case 'me' is not used
    return status_;
}
//${SMs::ToastOven::SM::doorClosed::heating::baking} .........................
QP::QMState const ToastOven::baking_s = {
    &ToastOven::heating_s, // superstate
    Q_STATE_CAST(&ToastOven::baking),
    Q_ACTION_CAST(&ToastOven::baking_e),
    Q_ACTION_CAST(0), // no exit action
    Q_ACTION_CAST(0)  // no intitial tran.
};
// ${SMs::ToastOven::SM::doorClosed::heating::baking}
QP::QState ToastOven::baking_e(ToastOven * const me) {
    printf("baking;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_ENTRY(&baking_s);
}
// ${SMs::ToastOven::SM::doorClosed::heating::baking}
QP::QState ToastOven::baking(ToastOven * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; // avoid compiler warning in case 'me' is not used
    return status_;
}
//${SMs::ToastOven::SM::doorClosed::off} .....................................
QP::QMState const ToastOven::off_s = {
    &ToastOven::doorClosed_s, // superstate
    Q_STATE_CAST(&ToastOven::off),
    Q_ACTION_CAST(&ToastOven::off_e),
    Q_ACTION_CAST(0), // no exit action
    Q_ACTION_CAST(0)  // no intitial tran.
};
// ${SMs::ToastOven::SM::doorClosed::off}
QP::QState ToastOven::off_e(ToastOven * const me) {
    printf("toaster-Off;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_ENTRY(&off_s);
}
// ${SMs::ToastOven::SM::doorClosed::off}
QP::QState ToastOven::off(ToastOven * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; // avoid compiler warning in case 'me' is not used
    return status_;
}
//${SMs::ToastOven::SM::doorOpen} ............................................
QP::QMState const ToastOven::doorOpen_s = {
    static_cast<QP::QMState const *>(0), // superstate (top)
    Q_STATE_CAST(&ToastOven::doorOpen),
    Q_ACTION_CAST(&ToastOven::doorOpen_e),
    Q_ACTION_CAST(&ToastOven::doorOpen_x),
    Q_ACTION_CAST(0)  // no intitial tran.
};
// ${SMs::ToastOven::SM::doorOpen}
QP::QState ToastOven::doorOpen_e(ToastOven * const me) {
    printf("door-Open,lamp-On;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_ENTRY(&doorOpen_s);
}
// ${SMs::ToastOven::SM::doorOpen}
QP::QState ToastOven::doorOpen_x(ToastOven * const me) {
    printf("lamp-Off;");
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_EXIT(&doorOpen_s);
}
// ${SMs::ToastOven::SM::doorOpen}
QP::QState ToastOven::doorOpen(ToastOven * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        // ${SMs::ToastOven::SM::doorOpen::CLOSE}
        case CLOSE_SIG: {
            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // transition-action table
                &doorClosed_s, // target state
                {
                    Q_ACTION_CAST(&doorOpen_x), // exit
                    Q_ACTION_CAST(&doorClosed_e), // entry
                    Q_ACTION_CAST(0) // zero terminator
                }
            };
            status_ = QM_TRAN_HIST(me->his_doorClosed, &tatbl_);
            break;
        }
        // ${SMs::ToastOven::SM::doorOpen::TERMINATE}
        case TERMINATE_SIG: {
            static struct {
                QP::QMState const *target;
                QP::QActionHandler act[3];
            } const tatbl_ = { // transition-action table
                &final_s, // target state
                {
                    Q_ACTION_CAST(&doorOpen_x), // exit
                    Q_ACTION_CAST(&final_e), // entry
                    Q_ACTION_CAST(0) // zero terminator
                }
            };
            status_ = QM_TRAN(&tatbl_);
            break;
        }
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    return status_;
}
//${SMs::ToastOven::SM::final} ...............................................
QP::QMState const ToastOven::final_s = {
    static_cast<QP::QMState const *>(0), // superstate (top)
    Q_STATE_CAST(&ToastOven::final),
    Q_ACTION_CAST(&ToastOven::final_e),
    Q_ACTION_CAST(0), // no exit action
    Q_ACTION_CAST(0)  // no intitial tran.
};
// ${SMs::ToastOven::SM::final}
QP::QState ToastOven::final_e(ToastOven * const me) {
    printf("-> final\nBye!Bye!\n");
    _exit(0);
    (void)me; // avoid compiler warning in case 'me' is not used
    return QM_ENTRY(&final_s);
}
// ${SMs::ToastOven::SM::final}
QP::QState ToastOven::final(ToastOven * const me, QP::QEvt const * const e) {
    QP::QState status_;
    switch (e->sig) {
        default: {
            status_ = QM_SUPER();
            break;
        }
    }
    (void)me; // avoid compiler warning in case 'me' is not used
    return status_;
}


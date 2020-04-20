#include "nouserinputtextedit.h"
#include <QPlainTextEdit>
#include <QDebug>

bool NoUserInputTextEdit::eventFilter(QObject* obj, QEvent* evt){
    if(!redirectKeyEvents)
        return false;
    if(evt->type() == QEvent::KeyPress || evt->type() == QEvent::KeyRelease){
        QKeyEvent* keyevt = static_cast<QKeyEvent*>(evt);
        // Ignore auto repeats
        if(keyevt->isAutoRepeat())
            return true;

        // modifiers(): Warning: This function cannot always be trusted. The user can confuse it by pressing both Shift keys simultaneously and releasing one of them, for example.
        emit macroKeyEvent(keyevt->key(), (evt->type() == QEvent::KeyPress), keyevt->modifiers());
        qDebug() << "Key" << (Qt::Key)keyevt->key() << "modifier" << keyevt->modifiers();
        return true;
    } else if (evt->type() == QEvent::ContextMenu) {
        // This is done so that we don't pop up endless context menus
        //if(redirectKeyEvents)
            return true;
    }
    return false;
}

NoUserInputTextEdit::NoUserInputTextEdit(QWidget* parent) : QPlainTextEdit(parent), redirectKeyEvents(false){
    installEventFilter(this);
}


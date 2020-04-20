#ifndef CLICKEVENTPUSHBUTTON_H
#define CLICKEVENTPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>

class ClickEventPushButton : public QPushButton
{
    Q_OBJECT
public:
    ClickEventPushButton(QWidget* parent = nullptr) : QPushButton(parent), clickedByMouse(false) {}
    inline bool isClickedByMouse() {
        bool temp = clickedByMouse;
        clickedByMouse = false;
        return temp;
    }
protected:
    virtual void mouseReleaseEvent(QMouseEvent* e) override;
private:
    bool clickedByMouse;
};
#endif // CLICKEVENTPUSHBUTTON_H

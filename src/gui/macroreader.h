#ifndef MACROREADER_H
#define MACROREADER_H

#include <QObject>
#include <QFile>
#include <QSocketNotifier>
#include <QElapsedTimer>

class MacroReader : public QObject {
Q_OBJECT

public:
    MacroReader(QStringList& macroPaths);
    ~MacroReader();
    inline void resetTimer() { (void)keyStrokeTime(); }

private:
    QStringList _macroPaths;
    QList<QFile*> fhandles;
    QList<QSocketNotifier*> fnotifiers;
    QElapsedTimer* timer;
    void keystrokeReceived(QFile* f);
    qint64 keyStrokeTime();

signals:
    void macroLineRead(QString key, qint64 ustime, bool keydown, bool printable);
    void macroReadError(QString key, QString modifiers);

public slots:
    void translateQKeyEvent(int keycode, bool down, Qt::KeyboardModifiers modifiers);
};

#endif // MACROREADER_H

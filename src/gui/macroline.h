#ifndef MACROLINE_H
#define MACROLINE_H
#include <QString>

class macroLine {
public:
    macroLine() = default;
    macroLine(QString _key, qint64 _usTime, bool _keyDown, bool _printable) : key(_key), usTime(_usTime), keyDown(_keyDown), printable(_printable) {}
    QString key;
    qint64 usTime;
    bool keyDown, printable;
};

#endif // MACROLINE_H

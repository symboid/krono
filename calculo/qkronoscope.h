
#ifndef __SYMBOID_KRONO_CALCULO_QKRONOSCOPE_H__
#define __SYMBOID_KRONO_CALCULO_QKRONOSCOPE_H__

#include "krono/calculo/defs.h"
#include "krono/calculo/kronoscope.h"
#include <QObject>

#define PROPERTY_COMMON(Type,name) \
private: \
    Type m_##name = 0; \
public: \
    void set_##name(Type name) \
    { \
        if (m_##name != name) \
        { \
            m_##name = name; \
            emit name##Changed(); \
        } \
    } \
Q_SIGNALS: \
    void name##Changed();

#define PROPERTY_MEMBER(Type,name) \
    PROPERTY_COMMON(Type,name) \
public: \
    Q_PROPERTY(Type name MEMBER m_##name WRITE set_##name NOTIFY name##Changed)

#define PROPERTY_RW(Type,name) \
    PROPERTY_COMMON(Type,name) \
public: \
    Q_PROPERTY(Type name READ name WRITE set_##name NOTIFY name##Changed) \
public: \
    Type name() const { return m_##name; }

class QKronoContour : public QObject
{
    Q_OBJECT

public:
    static constexpr const char* qml_name = "KronoContour";

public:
    QKronoContour(QObject* parent = Q_NULLPTR);

    PROPERTY_RW(int, marker)
    PROPERTY_RW(int, capacity)
    PROPERTY_RW(int, emission)

public:
    Q_PROPERTY(QString text READ text NOTIFY textChanged)
    virtual QString text() const { return ""; }
signals:
    void textChanged();
};

class QPhisContour : public QKronoContour
{
    Q_OBJECT
public:
    QPhisContour(QObject* parent = Q_NULLPTR) : QKronoContour(parent) {}
public:
    QString text() const override;
};

class QEmotContour : public QKronoContour
{
    Q_OBJECT
public:
    QEmotContour(QObject* parent = Q_NULLPTR) : QKronoContour(parent) {}
public:
    QString text() const override;
};

class QIntlContour : public QKronoContour
{
    Q_OBJECT
public:
    QIntlContour(QObject* parent = Q_NULLPTR) : QKronoContour(parent) {}
public:
    QString text() const override;
};

class QKronoScope : public QObject
{
    Q_OBJECT

public:
    static constexpr const char* qml_name = "KronoScope";

public:
    QKronoScope(QObject* parent = Q_NULLPTR);

    PROPERTY_MEMBER(int, year)
    PROPERTY_MEMBER(int, month)
    PROPERTY_MEMBER(int, day)

    PROPERTY_MEMBER(QKronoContour*, phisContour)
    PROPERTY_MEMBER(QKronoContour*, emotContour)
    PROPERTY_MEMBER(QKronoContour*, intlContour)
    PROPERTY_MEMBER(QKronoContour*, maskContour)

    Q_PROPERTY(int rootSum READ rootSum NOTIFY rootSumChanged)
    int rootSum() const;
signals:
    void rootSumChanged();

private:
    KronoScope mKronoScope;

private slots:
    void onDateChanged();
};

#endif // __SYMBOID_KRONO_CALCULO_QKRONOSCOPE_H__

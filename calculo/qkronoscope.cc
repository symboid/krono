
#include "krono/calculo/setup.h"
#include "krono/calculo/qkronoscope.h"

QKronoContour::QKronoContour(QObject* parent)
    : QObject(parent)
{
    connect(this, SIGNAL(capacityChanged()), this, SIGNAL(textChanged()));
    connect(this, SIGNAL(emissionChanged()), this, SIGNAL(textChanged()));
}

QString QPhisContour::text() const
{
    double A = double(capacity()) / 100.0;
    double B = double(emission()) / 100.0;
    double factor = 4.0 / 9.0;

    if (A < B)
    {
        if (A >= factor)
        {
            return tr("sanguine");
        }
        else if (B * factor < A)
        {
            return tr("moderate");
        }
        else if (B >= A * factor * 10.0)
        {
            return tr("sensitive");
        }
        else
        {
            return tr("choleric");
        }
    }
    else
    {
        if (B >= factor)
        {
            return tr("strong");
        }
        else if (B < A * factor)
        {
            return tr("phlegmatic");
        }
        else
        {
            return tr("melancholic");
        }
    }
}

QString QEmotContour::text() const
{
    double A = capacity(); A /= 100.0;
    double B = emission(); B /= 100.0;

    if (A < B)
    {
        if (A + B > 1.2)
        {
            return tr("passionate");
        }
        else if (B < 0.42)
        {
            return tr("cold");
        }
        else if (B / A > 2.0)
        {
            return tr("altruist");
        }
        else
        {
            return tr("empatic");
        }
    }
    else
    {
        if (A + B < 0.6)
        {
            return tr("cold");
        }
        else if (A < 0.65)
        {
            return tr("sloppy");
        }
        else
        {
            return tr("egoist");
        }
    }
}

QString QIntlContour::text() const
{
    double A = capacity(); A /= 100.0;
    double B = emission(); B /= 100.0;

    if (B > A)
    {
        if (B <= 0.41)
        {
            return tr("worker");
        }
        else if (A < 0.41)
        {
            return tr("philosopher");
        }
        else if (A / B < 0.82)
        {
            return tr("engineer");
        }
        else
        {
            return tr("harmonic");
        }
    }

    else if (B / A > 0.82)
    {
        return A+B > 1.15 ? tr("strategist") : tr("harmonic");
    }

    else
    {
        return A+B < 0.5 ? tr("artist") : tr("visionary");
    }
}

QKronoScope::QKronoScope(QObject* parent)
    : QObject(parent)
    , m_year(2000)
    , m_month(1)
    , m_day(1)
    , m_phisContour(new QPhisContour(this))
    , m_emotContour(new QEmotContour(this))
    , m_intlContour(new QIntlContour(this))
    , mKronoScope(m_year,m_month,m_day)
{
    connect(this, SIGNAL(yearChanged()), this, SLOT(onDateChanged()));
    connect(this, SIGNAL(monthChanged()), this, SLOT(onDateChanged()));
    connect(this, SIGNAL(dayChanged()), this, SLOT(onDateChanged()));
}

void QKronoScope::onDateChanged()
{
    mKronoScope.setDate(m_year, m_month, m_day);

    m_phisContour->set_marker(mKronoScope.phisContour().mMarker);
    m_phisContour->set_capacity(mKronoScope.phisContour().mCapacity);
    m_phisContour->set_emission(mKronoScope.phisContour().mEmission);

    m_emotContour->set_marker(mKronoScope.emotContour().mMarker);
    m_emotContour->set_capacity(mKronoScope.emotContour().mCapacity);
    m_emotContour->set_emission(mKronoScope.emotContour().mEmission);

    m_intlContour->set_marker(mKronoScope.intlContour().mMarker);
    m_intlContour->set_capacity(mKronoScope.intlContour().mCapacity);
    m_intlContour->set_emission(mKronoScope.intlContour().mEmission);
}

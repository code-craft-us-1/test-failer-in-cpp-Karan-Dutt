#pragma once
#ifdef TESTFAILER_EXPORTS
#define TESTFAILER_API __declspec(dllexport)
#else
#define TESTFAILER_API __declspec(dllimport)
#endif
#include <string>
#include "IWeatherReport.h"


namespace WeatherSpace {

    /// This is a stub for a weather sensor. For the sake of testing
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development

    class TESTFAILER_API SensorStub : public IWeatherSensor {


    public:
        SensorStub(int humidity, int precipitation, int temperatureInC, int windSpeed) :
        m_humidity(humidity), m_precipitation(precipitation), m_temperatureInC(temperatureInC), m_windSpeedKMPH(windSpeed)
        {
        }
        int Humidity() const override {
            return m_humidity;
        }

        int Precipitation() const override {
            return m_precipitation;
        }

        double TemperatureInC() const override {
            return m_temperatureInC;
        }

        int WindSpeedKMPH() const override {
            return m_windSpeedKMPH;
        }
    private:
        int m_humidity = 0;
        int m_precipitation = 0;
        int m_temperatureInC = 0;
        int m_windSpeedKMPH = 0;
    };

    // This is a function to predict the weather, based on readings
    // from a sensor
    TESTFAILER_API std::string Report(const IWeatherSensor& sensor);
}

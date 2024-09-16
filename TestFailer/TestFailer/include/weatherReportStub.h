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
        int Humidity() const override {
            return 72;
        }

        int Precipitation() const override {
            return 70;
        }

        double TemperatureInC() const override {
            return 26;
        }

        int WindSpeedKMPH() const override {
            return 52;
        }
    };

    class TESTFAILER_API FaultySensorStub : public IWeatherSensor {

    public:
        int Humidity() const override {
            return 72;
        }

        int Precipitation() const override {
            return 65;
        }

        double TemperatureInC() const override {
            return 26;
        }

        int WindSpeedKMPH() const override {
            return 49;
        }
    };

    // This is a function to predict the weather, based on readings
    // from a sensor
    TESTFAILER_API std::string Report(const IWeatherSensor& sensor);
}

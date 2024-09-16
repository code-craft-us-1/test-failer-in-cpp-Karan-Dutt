#include <gtest/gtest.h>
#include "../src/weatherReportStub.h"

namespace TestWeatherReport
{
    TEST(WeatherReport, Test_WeatherReport_Rainy)
    {
        constexpr WeatherSpace::SensorStub sensor;
        const std::string report = WeatherSpace::Report(sensor);
        EXPECT_NE(report.find("rain"), std::string::npos);
    }

    TEST(WeatherReport, Test_WeatherReport_HighPrecipitationAndLowWindspeed)
    {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        constexpr WeatherSpace::SensorStub sensor;

        // strengthen the assert to expose the bug
        // (function returns Sunny day, it should predict rain)
        const std::string report = WeatherSpace::Report(sensor);
        assert(report.length() > 0);
    }


    TEST(WeatherReport, Test_WeatherReport_HighPrecipitationAndVeryLowWindspeed)
    {
        constexpr WeatherSpace::FaultySensorStub faultySensor;
        const std::string report = WeatherSpace::Report(faultySensor);
    
        // The test should fail because the function incorrectly reports "Sunny day"
        // instead of recognizing stormy conditions with heavy rain.
        EXPECT_EQ(report, "Alert, Stormy with heavy rain");
    }
}
#include <gtest/gtest.h>
#include "../../TestFailer/include/weatherReportStub.h"

namespace TestWeatherReport
{
    TEST(WeatherReport, Test_WeatherReport_Rainy)
    {
        const WeatherSpace::SensorStub sensor(72, 70, 26, 52);
        const std::string report = WeatherSpace::Report(sensor);
        EXPECT_NE(report.find("rain"), std::string::npos);
    }

    TEST(WeatherReport, Test_WeatherReport_HighPrecipitationAndLowWindspeed)
    {
        // This instance of stub needs to be different-
        // to give high precipitation (>60) and low wind-speed (<50)
        const WeatherSpace::SensorStub sensor(72, 70, 26, 52);

        // strengthen the assert to expose the bug
        // (function returns Sunny day, it should predict rain)
        const std::string report = WeatherSpace::Report(sensor);
        assert(report.length() > 0);
    }


    TEST(WeatherReport, Test_WeatherReport_HighPrecipitationAndVeryLowWindspeed)
    {
        const WeatherSpace::SensorStub sensor(72, 65, 26, 49);
        const std::string report = WeatherSpace::Report(sensor);
    
        // The test should fail because the function incorrectly reports "Sunny day"
        // instead of recognizing stormy conditions with heavy rain.
        EXPECT_EQ(report, "Alert, Heavy rain");
    }
}
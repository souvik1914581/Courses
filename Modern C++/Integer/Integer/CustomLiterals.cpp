#include <iostream>
class Temperature {
	double m_temperature;	//stores temperature in degrees Celsius
public:
	Temperature() = default;
	Temperature(long double tempCelsius) :m_temperature(tempCelsius) {

	}
	double GetTemperature() const {
		return m_temperature;
	}
};

Temperature operator"" _fah(const long double tempFahrenheit) {
	return Temperature((tempFahrenheit - 32.0) * (5.0f / 9.0f));
}
#if 0
int main() {
	Temperature t1{ 97.0_fah };
	std::cout << t1.GetTemperature() << std::endl;
	return 0;
}
#endif
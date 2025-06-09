#include "Data.h"

float Data::CalculateHM()
{
	
	return std::accumulate(Frequency.begin(), Frequency.end(), 0.0f) / sumF_div_x;
}

void Data::GetData()
{
	ifstream inputFile("data.txt");
	if (!inputFile.is_open()) {
		cerr << "Error opening file: " << endl;
		return;
	}
	int value;
	while (inputFile >> value)
	{
		NumData.push_back(value);
	}
}

void Data::showdata()
{
	std::sort(NumData.begin(), NumData.end());

	// Finding minimum and maximum values
	int min_value = *std::min_element(NumData.begin(), NumData.end());
	int max_value = *std::max_element(NumData.begin(), NumData.end());
	
}


vector<std::pair<int, int>> Data::Findinterval()
{
	std::sort(NumData.begin(), NumData.end());
	
	int gap = 1 +( 3.3 * log10(NumData.size())) + 1;
	cout << "\n\n\t\tvector size is: " << NumData.size() << endl;
	cout << "\t\tgap is :" << gap << endl;
	// Finding minimum and maximum values
	int min_value = *std::min_element(NumData.begin(), NumData.end());
	int max_value = *std::max_element(NumData.begin(), NumData.end());

	int range =((max_value - min_value) / gap)+1;



	cout << "\t\trange is: " << range << "\n";

	int start_value = min_value;

	for (int i = 0; i < gap; i++)
	{
		intervals.push_back(std::make_pair(start_value, start_value+range-1));
		start_value += range ;
	}
	

	
	auto it = NumData.begin();  // Start with the beginning of the vector
	



	for (auto& Interval : intervals)
	{
		int countInRange = std::count_if(NumData.begin(), NumData.end(),
					[&](int num) { return num >= Interval.first && num <= Interval.second; });

				Frequency.push_back(countInRange);
	}

	

	return intervals;
}



void Data::showclassInterval()
{
	
	for (auto& x : intervals)
	{
		cout << x.first << "  " << x.second << endl;
	}
	
	for (auto& freq : Frequency)
	{
		cout << freq << endl;
	}
}

vector<int> Data::getFrequency()
{
	return Frequency;
}

void Data::showTable() {


	

	std::cout << "\n\t\t=======================================================================================================\n";
	std::cout << "\t\t class Interval        frequency       class boundaries           x           fx      logX       FlogX\n";
	std::cout << "\t\t=========================================================================================================\n";

	int i = 0;
	
	while (i < Frequency.size()) {
		std::cout << std::right << "\t\t"
			<< std::setw(6) << intervals[i].first << " - " << std::setw(6) << intervals[i].second
			<< std::setw(12) << Frequency[i]
			<< std::setw(17) << std::fixed << std::setprecision(1)
			<< static_cast<float>(intervals[i].first - 0.5) << " - "
			<< static_cast<float>(intervals[i].second + 0.5) << std::setprecision(0) << std::setw(15) << X[i] << std::setw(15) << Fx[i] 
			<< setprecision(3) << std::setw(10) << logx[i] << std::setw(10) << Flogx[i] << "\n";
		i++;
	}

	
	cout << "\n\n\t\tArithmetic Mean =  " << setprecision(3) <<CalculateAM() << "\n";
	cout << "\t\tGeometric Mean =  " << CalculateGm() << "\n";
	cout << "\t\tHarmonic Mean =  " << CalculateHM() << "\n";
}

void Data::Calculate_X_Fx_logx_flogX()
{
	for (auto& I : intervals)
	{
		X.push_back(static_cast<float>((I.first + I.second) / 2));
	}

	for (int i = 0; i < Frequency.size(); i++)
	{
		Fx.push_back(Frequency[i] * X[i]);
	}

	for (auto& x : X)
	{
		logx.push_back(log10(x));
	}

	for (int i = 0; i < Frequency.size(); i++)
	{
		Flogx.push_back(Frequency[i] * logx[i]);
	}

	/*for (auto& f : X)
	{
		cout << f << endl;
	}*/

	for (int i = 0; i < Frequency.size(); i++)
	{
		
		F_div_x.push_back(Frequency[i] / X[i]);
	}

	sumF_div_x = std::accumulate(F_div_x.begin(), F_div_x.end(), 0.0f);
	
}

float Data::CalculateAM() {
	if (Frequency.empty()) {
		// Handle division by zero or empty Frequency vector
		// For example, you might return a special value or throw an exception
		// Here, returning 0.0 as a placeholder
		return 0.0;
	}

	// Ensure floating-point division by casting at least one operand to float
	return static_cast<float>(std::accumulate(Fx.begin(), Fx.end(), 0.0f)) /
		static_cast<float>(std::accumulate(Frequency.begin(), Frequency.end(), 0.0f));
}

float Data::CalculateGm()
{

	

	float sumoffrequency= static_cast<float>(std::accumulate(Frequency.begin(), Frequency.end(), 0.0f));
	float sumofFlogX= static_cast<float>(std::accumulate(Flogx.begin(), Flogx.end(), 0.0f));

	return pow(10, sumofFlogX / sumoffrequency);
}



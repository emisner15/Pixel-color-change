#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include "Point.h"
#include "RemoveGreenEffect.h"
#include "RemoveRedEffect.h"
#include "RemoveBlueEffect.h"
#include "NegateRedEffect.h"
#include "NegateGreenEffect.h"
#include "NegateBlueEffect.h"
#include "AddNoiseEffect.h"
#include "AddHighContrast.h"
#include "AddGrayScale.h"
using namespace std;

int main(void)
{
    char selection;
    string input_file_name;
    string output_file_name;
    string line;
    int red, green, blue, g = 0;
    vector<string> lines{};
    vector<string> ignore_lines{};
    vector<Point> pixelVector{};


    cout << "Enter a PPM file to parse: ";
    getline(cin, input_file_name);
    cout << "Enter destination file: ";
    getline(cin, output_file_name);

    ifstream input_file{input_file_name};
    if(input_file.is_open() == true)
    {
        for(int i = 0; i < 3; i++)
        {
            getline(input_file, line);
            ignore_lines.push_back(line);
        }

        while(input_file.good() == true)
        {
            getline(input_file, line);
            istringstream iss(line);

            while(iss >> red >> green >> blue)
            {
                Point pixelObject;
                pixelObject.setRed(red);
                pixelObject.setGreen(green);
                pixelObject.setBlue(blue);
                pixelVector.push_back(pixelObject);
            }
        }
    }
    input_file.close();

    do
    {
        cout << "** Effects **" << endl
             << "        " << "1. Remove red" << endl
             << "        " << "2. Remove green" << endl
             << "        " << "3. Remove blue" << endl
             << "        " << "4. Negate red" <<endl
             << "        " << "5. Negate green" << endl
             << "        " << "6. Negate blue" << endl
             << "        " << "7. Add noise" << endl
             << "        " << "8. High contrast" <<endl
             << "        " << "9. Convert to grayscale" << endl
             << "        " << "-1. Exit program" << endl
             << "Selection: ";

        cin >> selection;

        switch(selection)
        {
            case '1' :
                {
                    RemoveRedEffect rmr{};
                    rmr.processImage(pixelVector);
                    break;
                }
            case '2' :
                {
                    RemoveGreenEffect rmg{};
                    rmg.processImage(pixelVector);
                    break;
                }
            case '3' :
                {
                    RemoveBlueEffect rmb{};
                    rmb.processImage(pixelVector);
                    break;
                }
            case '4' :
                {
                    NegateRedEffect nre{};
                    nre.processImage(pixelVector);
                    break;
                }
            case '5' :
                {
                    NegateGreenEffect nge{};
                    nge.processImage(pixelVector);
                    break;
                }
            case '6' :
                {
                    NegateBlueEffect nbe{};
                    nbe.processImage(pixelVector);
                    break;
                }
            case '7' :
                {
                    AddNoiseEffect ane{};
                    ane.processImage(pixelVector);
                    break;
                }
            case '8' :
                {
                    AddHighContrast ahc{};
                    ahc.processImage(pixelVector);
                    break;
                }
            case '9' :
                {
                    AddGrayScale ags{};
                    ags.processImage(pixelVector);
                    break;
                }
            default : break;
        }
    }
    while(selection == '1' || selection == '2' || selection == '3' || selection == '4' || selection == '5' || selection == '6' || selection == '7' || selection == '8' || selection == '9');

    ofstream output_file;
    output_file.open(output_file_name);
    for ( int i = 0; i < 3; i++ )
    {
        output_file << ignore_lines[i] << endl;
    }
    for(int i = 0; i < pixelVector.size(); i++)
    {
        g++;
        output_file << pixelVector[i].getRed() << " "
                    << pixelVector[i].getGreen() << " "
                    << pixelVector[i].getBlue() << " ";
        if(g == 5)
        {
            output_file << endl;
            g = 0;
        }
    }
    output_file.close();
}

 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct CorporateOffice
{
    // number of employees
    int numberOfEmployees = 100;
    // number of elevators
    int numberOfElevators = 2;
    // average salary
    float averageSalary = 70000.f;
    // HVAC temperature setting
    float temperatureSetting = 70.f;
    // address
    std::string address = "4321 Main St";

    struct Employee
    {
        std::string name = "John Doe";
        std::string jobTitle = "Staff";
        std::string department = "Administration";
        float salary = 50000.f;
        int timeAtCompany = 1;

        // 3 things they can do:
        void clockIn(double timeIn);
        double clockOut(double timeOut); //returns the time they worked that day
        void makeCopies(int numCopies);
    };

    // 3 things it can do:
    // target employee to call client
    void callClient(std::string clientName, Employee employee);
    // release payroll
    void releasePayroll(Employee employeeOne, Employee employeeTwo);
    // call security
    void callSecurity(Employee securityGuard);
};

struct DigitalKeyboard
{
    // Number of keys
    int NumbersOfKeys = 25;
    // Amount of voltage
    float voltage = 9.f;
    // Brightness of screen in nits
    int screentBrightness = 1000;
    // Amount of memory
    double memoryAmount = 80.0;
    // Sample rate
    int sampleRate = 44100;

    // 3 things it can do:
    // Change octave
    int chnageOctave(int newOctave); //returns the new octave number
    // Produce sound
    void produceSound();
    // Display wave form
    void displayWaveForm();
};

struct PhoneBook
{
    // Number of pages
    int numberOfPages = 1000;
    // Weight of book
    float bookWeight = 2.2f;
    // Telephone company
    std::string telephoneCompany = "Yellowpages";
    // Age of book
    float bookAge = 3.1f;
    // Strength of glue
    float glueStrength = 1.7f;

    // 3 things it can do:
    // Display contact information
    std::string contactInformationDiplay(std::string contactName); //returns the contact information
    // Open to random page
    void openToRandomPage();
    // Disintigrate
    void disintigrate();
};

struct ElectricHeater
{
    // Wattage
    float wattage = 1500.f;
    // Number of settings
    int numberOfSettings = 3;
    // Temperature setting
    int temperatureSetting = 72;
    // Pivot mode
    char pivotMode = 'A';
    // Power saving mode
    bool powerSavingMode = true;

    struct HeatingElement
    {
        int resistance = 10;
        int voltage = 120;
        float elementLength = 24.0f;
        std::string supportType = "Embedded";
        std::string layoutType = "Open Coil";

        // 3 things it can do:
        void slowCoolDown(int coolDownTime = 10);
        void slowHeatUp(int heatUpTime = 10);
        void changeTemperature(int newTemperature);
    };
    
    // 3 things it can do:
    // Produce heat
    void produceHeat();
    // Trigger countdown timer
    void triggerCountdownTimer(float tippingMovement);
    // Display current temperature
    int displayCurrentTemperature(); //returns the current temperature
};

struct Oscillator
{
    // Pitch
    float pitch = 440.f;
    // Type of wave form
    std::string waveForm = "Sawtooth";
    // Pulsewidth (abstract value)
    float pulseWidth = 0.5f;
    // Volume in dB
    double volume = 50.0;
    // Octave (numerical value)
    int octave = 16;

    // 3 things it can do:
    // Change pitch
    float changePitch(float newPitch); //returns the new pitch
    // Change pulsewidth
    float changePulseWidth(float newPulseWidth); //returns the new pulsewidth
    // Change octave
    int changeOctave(int newOctave); //returns the new octave
};

struct EnvelopeGenerator
{
    // Attack speed
    double attackSpeed = 0.01;
    // Decay speed
    double decaySpeed = 0.05;
    // Sustain level
    double sustainLevel = 0.5;
    // Release speed
    double releaseSpeed = 0.1;
    // Delay length
    double delayLength = 0.0;

    // 3 things it can do:
    // Play short envelope
    void playShortEnvelope(double newReleaseSpeed); //returns the new release speed
    // Play long envelope
    void playLongEnvelope(double newAttackSpeed, double newReleaseSpeed); //returns the new attack and release speed
    // Remain open
    void remainOpen();
};

struct BandPassFilter
{
    // High pass cutoff
    float highPassCutoff = 20.f;
    // Low pass cutoff
    float lowPassCutoff = 1000.f;
    // High pass resonance
    float highPassResonance = 0.f;
    // Low pass resonance
    float lowPassResonance = 0.f;
    // Filter slope
    std::string filterSlope = "12 dB/Oct";

    // 3 things it can do:
    // Change cutoff
    float changeBPCutoff(float newBPCutoff); //returns the new cutoff
    // Change resonance
    float changeBPResonance(float newBPResonance);
    // Change filter slope
    std::string changeFilterSlope(std::string newFilterSlope); //returns the new filter slope
};

struct SampleAndHold
{
    //Clock frequency
    float clockFrequency = 5.f;
    // Input voltage
    double inputVoltage = 2.0;
    // Output amplitude
    float output = 5.f;
    // Output slew rate
    double outputSlewRate = 0.0;
    // Clock randomness (arbitrary value)
    float clockRandomness = 0.5f;

    // 3 things it can do:
    // Change clock frequency
    float changeClockFrequency(float newClockFrequency); //returns the new clock frequency
    // Change clock randomness
    float changeClockRandomness(float newClockRandomness); //returns the new clock randomness
    // Change output amplitude
    float changeOutput(float newOutput); //returns the new output
};

struct Delay
{
    // Delay rate
    std::string delayRate = "1/4";
    //Feedback amount (float)
    float feedbackAmount = 0.5f;
    // Wet volume (double)
    double wetVolume = 0.5;
    // Dry volume (double)
    double dryVolume = 0.5;
    // Delay fidelity (int)
    int delayFidelity = 10;

    // 3 things it can do:
    // Change delay rate
    std::string changeDelayRate(std::string newDelayRate); //returns the new delay rate
    // Change feedback amount
    float changeFeedbackAmount(float newFeedbackAmount); //returns the new feedback amount
    // Change wet volume
    double changeWetVolume(double newWetVolume); //returns the new wet volume
};

struct ImaginaryKorg
{
    // Oscillator
    Oscillator oscillator;
    // Envelope Generator
    EnvelopeGenerator envelopeGenerator;
    // "Band Pass" Filter
    BandPassFilter bandPassFilter;
    // Sample and Hold
    SampleAndHold sampleAndHold;
    // Delay
    Delay delay;

    // 3 things it can do:
    // Play pretty note
    void playPrettyNote(Oscillator sawtoothNote, EnvelopeGenerator newEnvelope, Delay prettyDelay);
    // Play noise
    void playNoise(Oscillator noise);
    // Randomly generate notes
    void randomlyGenerateNotes(SampleAndHold randomPattern);
};

int main()
{
    std::cout << "good to go!" << std::endl;
}

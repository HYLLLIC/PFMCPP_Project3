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

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Limb
    {
        int step = 1;

        void stepForward();
        int stepSize();    
    };

    Limb leftFoot;
    Limb rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Limb::stepForward()
{
    step += 1;
}

int Person::Limb::stepSize()
{
    return step;
}   

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    } 
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    
    distanceTraveled = (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
}

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
    int numberOfEmployees = 100;
    int numberOfElevators = 2;
    float averageSalary = 70000.f;
    float temperatureSetting = 70.f;
    std::string address = "4321 Main St";

    struct Employee
    {
        std::string name = "John Doe";
        std::string jobTitle = "Staff";
        std::string department = "Administration";
        float salary = 50000.f;
        int timeAtCompany = 1;

        void clockIn(double timeIn);
        void clockOut(double timeOut);
        void makeCopies(int numCopies);
    };

    void callClient(std::string clientName, Employee employee);
    void releasePayroll(Employee employeeOne, Employee employeeTwo);
    void callSecurity(Employee securityGuard);
};

    void CorporateOffice::Employee::clockIn(double timeIn)
    {
        std::cout << "Welcome, it's " << timeIn << "AM" << std::endl;
    }
    
    void CorporateOffice::Employee::clockOut(double timeOut)
    {
        std::cout << "Goodbye, it's " << timeOut << "PM" << std::endl;
    }

    void CorporateOffice::Employee::makeCopies(int numCopies)
    {
        std::cout << "Now printing " << numCopies << " copies" << std::endl;
    }

    void CorporateOffice::callClient(std::string clientName, Employee employee)
    {
        std::cout << "Now " << employee.name << " is calling " << clientName << std::endl;
    }

    void CorporateOffice::releasePayroll(Employee employeeOne, Employee employeeTwo)
    {
        employeeOne.salary += 4000.f;
        employeeTwo.salary += 4000.f;
    }

    void CorporateOffice::callSecurity(Employee securityGuard)
    {
        securityGuard.name = "THE BOSS, NOW";
    }

struct DigitalKeyboard
{
    int NumbersOfKeys = 25;
    float voltage = 9.f;
    int screentBrightness = 1000;
    double memoryAmount = 80.0;
    int sampleRate = 44100;

    int chnageOctave(int newOctave);
    void produceSound();
    void displayWaveForm();
};

struct PhoneBook
{
    int numberOfPages = 1000;
    float bookWeight = 2.2f;
    std::string telephoneCompany = "Yellowpages";
    float bookAge = 3.1f;
    float glueStrength = 1.7f;

    std::string contactInformationDiplay(std::string contactName);
    void openToRandomPage();
    void disintigrate();
};

    std::string PhoneBook::contactInformationDiplay(std::string contactName)
    {
        std::string phoneNumber = contactName + " 555-5555";
        return phoneNumber;
    }

    void PhoneBook::openToRandomPage()
    {
        int min = 1;
        int max = numberOfPages;
    
        int randomNumber = rand() % (max - min + 1) + min;
        std::cout << "Opening page " << randomNumber << std::endl;
    }

    void PhoneBook::disintigrate()
    {
        std::cout << "Uahghghgllll I'm disintigrating" << std::endl;
    }

struct ElectricHeater
{
    float wattage = 1500.f;
    int numberOfSettings = 3;
    int temperatureSetting = 72;
    char pivotMode = 'A';
    bool powerSavingMode = true;

    struct HeatingElement
    {
        int resistance = 10;
        int voltage = 120;
        float elementLength = 24.0f;
        std::string supportType = "Embedded";
        std::string layoutType = "Open Coil";

        void slowCoolDown(int coolDownTime = 10);
        void slowHeatUp(int heatUpTime = 10);
        void changeTemperature(int newTemperature);
    };
    
    void produceHeat();
    void triggerCountdownTimer(float tippingMovement);
    int displayCurrentTemperature();
};

struct Oscillator
{
    float pitch = 440.f;
    std::string waveForm = "Sawtooth";
    float pulseWidth = 0.5f;
    double volume = 50.0;
    int octave = 16;

    float changePitch(float newPitch);
    float changePulseWidth(float newPulseWidth);
    int changeOctave(int newOctave);
};

struct EnvelopeGenerator
{
    double attackSpeed = 0.01;
    double decaySpeed = 0.05;
    double sustainLevel = 0.5;
    double releaseSpeed = 0.1;
    double delayLength = 0.0;

    void playShortEnvelope(double newReleaseSpeed);
    void playLongEnvelope(double newAttackSpeed, double newReleaseSpeed);
    void remainOpen();
};

struct BandPassFilter
{
    float highPassCutoff = 20.f;
    float lowPassCutoff = 1000.f;
    float highPassResonance = 0.f;
    float lowPassResonance = 0.f;
    std::string filterSlope = "12 dB/Oct";

    float changeBPCutoff(float newBPCutoff);
    float changeBPResonance(float newBPResonance);
    std::string changeFilterSlope(std::string newFilterSlope);
};

struct SampleAndHold
{
    float clockFrequency = 5.f;
    double inputVoltage = 2.0;
    float output = 5.f;
    double outputSlewRate = 0.0;
    float clockRandomness = 0.5f;

    float changeClockFrequency(float newClockFrequency);
    float changeClockRandomness(float newClockRandomness);
    float changeOutput(float newOutput);
};

struct Delay
{
    std::string delayRate = "1/4";
    float feedbackAmount = 0.5f;
    double wetVolume = 0.5;
    double dryVolume = 0.5;
    int delayFidelity = 10;

    std::string changeDelayRate(std::string newDelayRate);
    float changeFeedbackAmount(float newFeedbackAmount);
    double changeWetVolume(double newWetVolume);
};

struct ImaginaryKorg
{
    Oscillator oscillator;
    EnvelopeGenerator envelopeGenerator;
    BandPassFilter bandPassFilter;
    SampleAndHold sampleAndHold;
    Delay delay;

    void playPrettyNote(Oscillator sawtoothNote, EnvelopeGenerator newEnvelope, Delay prettyDelay);
    void playNoise(Oscillator noise);
    void randomlyGenerateNotes(SampleAndHold randomPattern);
};

int main()
{
    std::cout << "good to go!" << std::endl;
}

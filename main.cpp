/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





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

    int changeOctave(int newOctave);
    void produceSound();
    void displayWaveForm();
};

int DigitalKeyboard::changeOctave(int newOctave)
{
    int octave = newOctave;
    return octave;
}

void DigitalKeyboard::produceSound()
{
    std::cout << "Now playing sound" << std::endl;
}

void DigitalKeyboard::displayWaveForm()
{
    std::cout << "Now displaying waveform" << std::endl;
    std::cout << "   ~~~~    ~~~~    ~~~~    " << std::endl;
    std::cout << " ~      ~        ~      ~  " << std::endl;
    std::cout << "~        ~      ~        ~ " << std::endl;
}

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

void ElectricHeater::HeatingElement::slowCoolDown(int coolDownTime)
{
    std::cout << "It's time to cool down, it will take " << coolDownTime << "seconds" << std::endl;
}

void ElectricHeater::HeatingElement::slowHeatUp(int heatUpTime)
{
    std::cout << "It's time to heat up, it will take " << heatUpTime << "seconds" << std::endl;
}

void ElectricHeater::HeatingElement::changeTemperature(int newTemperature)
{
    voltage = 0;
    std::cout << "Haha gotcha, you wanted " << newTemperature << std::endl;
}

void ElectricHeater::produceHeat()
{
    powerSavingMode = false;
}

void ElectricHeater::triggerCountdownTimer(float tippingMovement)
{
    if (tippingMovement > 0.5f)
    {
        powerSavingMode = true;
    }
}

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

float Oscillator::changePitch(float newPitch)
{
    pitch = newPitch;
    return pitch;
}

float Oscillator::changePulseWidth(float newPulseWidth)
{
    pulseWidth = newPulseWidth;
    return pulseWidth;
}

int Oscillator::changeOctave(int newOctave)
{
    octave = octave + (newOctave * 16);
    return octave;
}

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

void EnvelopeGenerator::playShortEnvelope(double newReleaseSpeed)
{
    attackSpeed = 0.01;
    decaySpeed = 0.01;
    releaseSpeed = newReleaseSpeed;
    sustainLevel = 0.0;
    delayLength = 0.0;
}

void EnvelopeGenerator::playLongEnvelope(double newAttackSpeed, double newReleaseSpeed)
{
    attackSpeed = newAttackSpeed;
    decaySpeed = 0.1;
    releaseSpeed = newReleaseSpeed;
    sustainLevel = 0.5;
    delayLength = 0.1;
}

void EnvelopeGenerator::remainOpen()
{
    attackSpeed = 0.0;
    decaySpeed = 0.0;
    releaseSpeed = 1.0;
    sustainLevel = 1.0;
    delayLength = 0.0;
}

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

float BandPassFilter::changeBPCutoff(float newBPCutoff)
{
    highPassCutoff = newBPCutoff - 20;
    lowPassCutoff = newBPCutoff + 20;
    std::cout << newBPCutoff << "Hz" << std::endl;
    return newBPCutoff;
}

float BandPassFilter::changeBPResonance(float newBPResonance)
{
    highPassResonance = newBPResonance;
    lowPassResonance = newBPResonance;
    std::cout << newBPResonance << "Q" << std::endl;
    return newBPResonance;
}

std::string BandPassFilter::changeFilterSlope(std::string newFilterSlope)
{
    filterSlope = newFilterSlope;
    std::cout << newFilterSlope << std::endl;
    return newFilterSlope;
}

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

float SampleAndHold::changeClockFrequency(float newClockFrequency)
{
    clockRandomness = 0.0;
    clockFrequency = newClockFrequency;
    return newClockFrequency;
}

float SampleAndHold::changeClockRandomness(float newClockRandomness)
{
    outputSlewRate = 0.0;
    clockRandomness = newClockRandomness;
    return newClockRandomness;
}

float SampleAndHold::changeOutput(float newOutput)
{
    outputSlewRate = 0.0;
    output = newOutput;
    return newOutput;
}

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

std::string Delay::changeDelayRate(std::string newDelayRate)
{
    delayRate = newDelayRate;
    return delayRate;
}

float Delay::changeFeedbackAmount(float newFeedbackAmount)
{
    feedbackAmount = newFeedbackAmount;
    return newFeedbackAmount;
}

double Delay::changeWetVolume(double newWetVolume)
{
    wetVolume = newWetVolume;
    dryVolume = 1.0 - newWetVolume;
    return newWetVolume;
}

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

void ImaginaryKorg::playPrettyNote(Oscillator sawtoothNote, EnvelopeGenerator newEnvelope, Delay prettyDelay)
{
    oscillator.changePitch(sawtoothNote.changePitch(770.f));
    bandPassFilter.changeBPCutoff(prettyDelay.changeFeedbackAmount(0.5f));
    envelopeGenerator.playLongEnvelope(newEnvelope.attackSpeed, newEnvelope.releaseSpeed);
}

void ImaginaryKorg::playNoise(Oscillator noise)
{
    oscillator.changePitch(noise.changePitch(1000.f));
    sampleAndHold.changeClockRandomness(0.5f);
    sampleAndHold.changeClockFrequency(100.0f);
}

void ImaginaryKorg::randomlyGenerateNotes(SampleAndHold randomPattern)
{
    oscillator.changePitch(randomPattern.changeOutput(0.5f));
}

int main()
{
    Example::main();

    //add your code between these =====
    //==============================



    //==============================
    std::cout << "good to go!" << std::endl;
}

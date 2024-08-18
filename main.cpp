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
    CorporateOffice();
    int numberOfEmployees = 100;
    int numberOfElevators = 2;
    float averageSalary = 70000.f;
    float temperatureSetting = 70.f;
    std::string address = "4321 Main St";

    struct Employee
    {
        Employee();
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

CorporateOffice::CorporateOffice()
{
    std::cout << "The new corporate office is ready for business!" << std::endl;
}

CorporateOffice::Employee::Employee()
{
    std::cout << "Welcome to the family, " << name << " as the new Emplyee!" << std::endl;
}

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
    DigitalKeyboard();
    int NumbersOfKeys = 25;
    float voltage = 9.f;
    int screentBrightness = 1000;
    double memoryAmount = 80.0;
    int sampleRate = 44100;

    int changeOctave(int newOctave);
    void produceSound();
    void displayWaveForm();
};

DigitalKeyboard::DigitalKeyboard ()
{
    std::cout << "Booting up new keyboard!" << std::endl;
}

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
    PhoneBook();
    int numberOfPages = 1000;
    float bookWeight = 2.2f;
    std::string telephoneCompany = "Yellowpages";
    float bookAge = 3.1f;
    float glueStrength = 1.7f;

    std::string contactInformationDiplay(std::string contactName);
    void openToRandomPage();
    void disintigrate();
};

PhoneBook::PhoneBook()
{
    std::cout << "Delivering new Phonebook!" << std::endl;
}

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
    ElectricHeater();
    float wattage = 1500.f;
    int numberOfSettings = 3;
    int temperatureSetting = 72;
    char pivotMode = 'A';
    bool powerSavingMode = true;

    struct HeatingElement
    {
        HeatingElement();
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

ElectricHeater::ElectricHeater()
{
    std::cout << "Firing up new heater!" << std::endl;
}

ElectricHeater::HeatingElement::HeatingElement()
{
    std::cout << "New heating element added!" << std::endl;
}

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

int ElectricHeater::displayCurrentTemperature()
{
    return temperatureSetting;
}

struct Oscillator
{
    Oscillator();
    float pitch = 440.f;
    std::string waveForm = "Sawtooth";
    float pulseWidth = 0.5f;
    double volume = 50.0;
    int octave = 16;

    float changePitch(float newPitch);
    float changePulseWidth(float newPulseWidth);
    int changeOctave(int newOctave);
};

Oscillator::Oscillator()
{
    std::cout << "We have a new oscillator!" << std::endl;
}

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
    EnvelopeGenerator();
    double attackSpeed = 0.01;
    double decaySpeed = 0.05;
    double sustainLevel = 0.5;
    double releaseSpeed = 0.1;
    double delayLength = 0.0;

    void playShortEnvelope(double newReleaseSpeed);
    void playLongEnvelope(double newAttackSpeed, double newReleaseSpeed);
    void remainOpen();
};

EnvelopeGenerator::EnvelopeGenerator()
{
    std::cout << "New envelope ready!" << std::endl;
}

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
    BandPassFilter();
    float highPassCutoff = 20.f;
    float lowPassCutoff = 1000.f;
    float highPassResonance = 0.f;
    float lowPassResonance = 0.f;
    std::string filterSlope = "12 dB/Oct";

    float changeBPCutoff(float newBPCutoff);
    float changeBPResonance(float newBPResonance);
    std::string changeFilterSlope(std::string newFilterSlope);
};

BandPassFilter::BandPassFilter()
{
    std::cout << "Band pass filter is ready!" << std::endl;
}

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
    SampleAndHold();
    float clockFrequency = 5.f;
    double inputVoltage = 2.0;
    float output = 5.f;
    double outputSlewRate = 0.0;
    float clockRandomness = 0.5f;

    float changeClockFrequency(float newClockFrequency);
    float changeClockRandomness(float newClockRandomness);
    float changeOutput(float newOutput);
};

SampleAndHold::SampleAndHold()
{
    std::cout << "New Sample and Hold is ready!" << std::endl;
}

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
    Delay();
    std::string delayRate = "1/4";
    float feedbackAmount = 0.5f;
    double wetVolume = 0.5;
    double dryVolume = 0.5;
    int delayFidelity = 10;

    std::string changeDelayRate(std::string newDelayRate);
    float changeFeedbackAmount(float newFeedbackAmount);
    double changeWetVolume(double newWetVolume);
};

Delay::Delay()
{
    std::cout << "New delay is ready, ready, ready..." << std::endl;
}

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
    ImaginaryKorg();
    Oscillator oscillator;
    EnvelopeGenerator envelopeGenerator;
    BandPassFilter bandPassFilter;
    SampleAndHold sampleAndHold;
    Delay delay;

    void playPrettyNote(Oscillator sawtoothNote, EnvelopeGenerator newEnvelope, Delay prettyDelay);
    void playNoise(Oscillator noise);
    void randomlyGenerateNotes(SampleAndHold randomPattern);
};

ImaginaryKorg::ImaginaryKorg()
{
    std::cout << "New Imaginary Korg is ready!" << std::endl;
}

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
    CorporateOffice orphanCrushingMachineInc;
    
    CorporateOffice::Employee jackie;
    
    jackie.name = "Jackie";
    jackie.clockIn(9.0);
    jackie.clockOut(17.0);
    jackie.makeCopies(20);

    orphanCrushingMachineInc.callClient("HYLLLIC", jackie);
    orphanCrushingMachineInc.releasePayroll(jackie, jackie);
    orphanCrushingMachineInc.callSecurity(jackie);

    std::cout << "Welcome " << jackie.name << "! Please report to " << jackie.department << std::endl;
    
    std::cout << "Boy, those " << jackie.salary << " dollars are gonna be a lot of money! " << std::endl;

    DigitalKeyboard lilMidiKeyboard;

    lilMidiKeyboard.changeOctave(2);
    lilMidiKeyboard.produceSound();
    lilMidiKeyboard.displayWaveForm();

    PhoneBook olYellowPages;

    olYellowPages.contactInformationDiplay("HYLLLIC INC");
    olYellowPages.openToRandomPage();
    olYellowPages.disintigrate();

    ElectricHeater heater;

    heater.produceHeat();
    heater.triggerCountdownTimer(0.5f);
    heater.displayCurrentTemperature();

    ElectricHeater::HeatingElement newCoil;

    newCoil.slowCoolDown(10);
    newCoil.slowHeatUp(10);
    newCoil.changeTemperature(80);

    Oscillator oscOne;

    oscOne.changePitch(777.f);
    oscOne.changePulseWidth(0.1f);
    oscOne.changeOctave(2);

    EnvelopeGenerator ADSROne;

    ADSROne.playShortEnvelope(.22);
    ADSROne.playLongEnvelope(.57, 1.5);
    ADSROne.remainOpen();

    BandPassFilter newBPFilter;

    newBPFilter.changeBPCutoff(1250.7f);
    newBPFilter.changeBPResonance(0.25f);
    newBPFilter.changeFilterSlope("24 dB/Oct");

    SampleAndHold newSampAndHold;

    newSampAndHold.changeClockFrequency(3.5f);
    newSampAndHold.changeClockRandomness(0.75f);
    newSampAndHold.changeOutput(0.2f);

    Delay newDelay;

    newDelay.changeDelayRate("1/8");
    newDelay.changeFeedbackAmount(0.8f);
    newDelay.changeWetVolume(0.33);

    std::cout << "if my wet amount is " << newDelay.wetVolume << ", then my dry amount is " << newDelay.dryVolume << std::endl;

    ImaginaryKorg korg;
    
    korg.playPrettyNote(oscOne, ADSROne, newDelay);
    korg.playNoise(oscOne);
    korg.randomlyGenerateNotes(newSampAndHold);

    std::cout << "Let me see what the octave is: " << korg.oscillator.octave << " and what the pitch is: " << korg.oscillator.pitch << ", and good lord that feedback is too high: " << korg.delay.feedbackAmount << std::endl;
    
    korg.delay.feedbackAmount = .1f;
    
    std::cout << "Now lets see if that new feedback sounds better: " << korg.delay.feedbackAmount << std::endl;

    //==============================
    std::cout << "good to go!" << std::endl;
}

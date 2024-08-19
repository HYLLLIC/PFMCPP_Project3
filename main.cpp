/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




struct CorporateOffice
{
    int numberOfEmployees;
    int numberOfElevators;
    float averageSalary;
    float temperatureSetting;
    std::string address;

    CorporateOffice();

    struct Employee
    {
        std::string name;
        std::string jobTitle;
        std::string department;
        float salary;
        int timeAtCompany;

        Employee();    

        void clockIn(double timeIn);
        void clockOut(double timeOut);
        void makeCopies(int numCopies);
    };

    void callClient(std::string clientName, Employee employee);
    void releasePayroll(Employee employeeOne, Employee employeeTwo);
    void callSecurity(Employee securityGuard);
};

CorporateOffice::CorporateOffice() :
numberOfEmployees(100),
numberOfElevators(2),
averageSalary(70000.f),
temperatureSetting(70.f),
address("4321 Main St")
{
    std::cout << "The new corporate office is ready for business!" << std::endl;
}

CorporateOffice::Employee::Employee() :
name("John Doe"),
jobTitle("Staff"),
department("Administration"),
salary(50000.f),
timeAtCompany(1)
{
    std::cout << "Welcome to the family, " << name << " as the new Emplyee!" << std::endl;
}

void CorporateOffice::Employee::clockIn(double timeIn)
{
    std::cout << "Welcome, " << name <<  " it is " << timeIn << "AM" << std::endl;
}

void CorporateOffice::Employee::clockOut(double timeOut)
{
    std::cout << "Goodbye, it's " << timeOut << "PM" << std::endl;
}

void CorporateOffice::Employee::makeCopies(int numCopies)
{
    std::cout << "Now printing " << numCopies << " copies for the " << department << " meeting." << std::endl;
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
    int screentBrightness;
    double memoryAmount = 80.0;
    int sampleRate = 44100;

    DigitalKeyboard();

    int changeOctave(int newOctave);
    void produceSound();
    void displayWaveForm();
};

DigitalKeyboard::DigitalKeyboard () :
screentBrightness(1000)
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
    std::cout << "Now displaying waveform, sample rate is " << sampleRate << "." << std::endl;
    std::cout << "   ~~~~    ~~~~    ~~~~    " << std::endl;
    std::cout << " ~      ~        ~      ~  " << std::endl;
    std::cout << "~        ~      ~        ~ " << std::endl;
}

struct PhoneBook
{
    int numberOfPages;
    float bookWeight;
    std::string telephoneCompany;
    float bookAge;
    float glueStrength;

    std::string contactInformationDiplay(std::string contactName);
    void openToRandomPage();
    void disintigrate();

    PhoneBook();
};

PhoneBook::PhoneBook() :
numberOfPages(1000),
bookWeight(2.2f),
telephoneCompany("Yellowpages"),
bookAge(3.1f),
glueStrength(1.7f)
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
    std::cout << "Opening page, out of " << numberOfPages << " pages, we open to "<< randomNumber << std::endl;
}

void PhoneBook::disintigrate()
{
    std::cout << "Uahghghgllll the " << telephoneCompany << " phone book is disintigrating" << std::endl;
}

struct ElectricHeater
{
    float wattage = 1500.f;
    int numberOfSettings = 3;
    int temperatureSetting;
    char pivotMode = 'A';
    bool powerSavingMode = true;

    ElectricHeater();

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

ElectricHeater::ElectricHeater() :
temperatureSetting(72)
{
    std::cout << "Firing up new heater!" << std::endl;
}

ElectricHeater::HeatingElement::HeatingElement()
{
    std::cout << "New heating element added!" << std::endl;
}

void ElectricHeater::HeatingElement::slowCoolDown(int coolDownTime)
{
    std::cout << "It's time to cool down, it will take " << layoutType << " coil " << coolDownTime << "seconds to cool down." << std::endl;
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
    std::cout << "Now producing heat, temperature setting is " << temperatureSetting << std::endl;
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
    std::cout << "Current temperature is " << temperatureSetting << std::endl;
    return temperatureSetting;
}

struct Oscillator
{
    float pitch = 440.f;
    std::string waveForm;
    float pulseWidth;
    double volume;
    int octave = 16;

    Oscillator();

    float changePitch(float newPitch);
    float changePulseWidth(float newPulseWidth);
    int changeOctave(int newOctave);

};

Oscillator::Oscillator() :
waveForm("Sawtooth"),
pulseWidth(0.5f),
volume(50.0)
{
    std::cout << "We have a new oscillator!" << std::endl;
}

float Oscillator::changePitch(float newPitch)
{
    pitch = newPitch;
    std::cout << "The pitch is now " << pitch << std::endl;
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
    double attackSpeed;
    double decaySpeed;
    double sustainLevel;
    double releaseSpeed;
    double delayLength = 0.0;

    EnvelopeGenerator();

    void playShortEnvelope(double newReleaseSpeed);
    void playLongEnvelope(double newAttackSpeed, double newReleaseSpeed);
    void remainOpen();
};

EnvelopeGenerator::EnvelopeGenerator() :
attackSpeed(0.01),
decaySpeed(0.05),
sustainLevel(0.5),
releaseSpeed(0.1)
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
    std::cout << "Envelope is now playing short envelope with release speed: " << releaseSpeed << std::endl;
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
    std::string filterSlope;

    BandPassFilter();

    float changeBPCutoff(float newBPCutoff);
    float changeBPResonance(float newBPResonance);
    std::string changeFilterSlope(std::string newFilterSlope);
};

BandPassFilter::BandPassFilter() :
filterSlope("12 dB/Oct")
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
    std::cout << "The filter slope is now " << newFilterSlope << std::endl;
    return newFilterSlope;
}

struct SampleAndHold
{
    float clockFrequency = 5.f;
    double inputVoltage = 2.0;
    float output = 5.f;
    double outputSlewRate;
    float clockRandomness;

    SampleAndHold();

    float changeClockFrequency(float newClockFrequency);
    float changeClockRandomness(float newClockRandomness);
    float changeOutput(float newOutput);
};

SampleAndHold::SampleAndHold() :
outputSlewRate(0.0),
clockRandomness(0.5f)
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
    std::cout << "The slew rate is currently " << outputSlewRate << std::endl;
    std::cout << "The clock randomness is currently " << clockRandomness << std::endl;
    return newOutput;
}

struct Delay
{
    std::string delayRate;
    float feedbackAmount = 0.5f;
    double wetVolume = 0.5;
    double dryVolume = 0.5;
    int delayFidelity = 10;

    Delay();

    std::string changeDelayRate(std::string newDelayRate);
    float changeFeedbackAmount(float newFeedbackAmount);
    double changeWetVolume(double newWetVolume);
};

Delay::Delay() :
delayRate("1/4")
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
    std::cout << "The delay rate is currently " << delayRate << std::endl;
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

    ImaginaryKorg();

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

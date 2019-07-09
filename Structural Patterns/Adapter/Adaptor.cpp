#include <iostream>
using namespace std;
#include <memory>

class ILightningType {
public:
    ILightningType() = default;
    virtual ~ILightningType() = default;
    virtual void charge() = 0;
};

class IUsbCType {
public:
    IUsbCType() = default;
    virtual ~IUsbCType() = default;
    virtual void charge() = 0;
};

class UsbCCharger : public IUsbCType {
public:
    void charge() override {
        cout << "Charging with UsbCCharger..." << endl;
    }
    ~UsbCCharger() {
        cout << "Destructing UsbCCharger!" << endl;
    }
};

class IphoneX {
private:
    ILightningType* mCharger;
public:
    void setLightningCharger(ILightningType* charger) { mCharger = charger; }
    void charge() {
        cout << "Charging my IphoneX..." << endl;
        mCharger->charge();
    }
    ~IphoneX() {
        cout << "Destructing IphoneX!" << endl;
    }
};

class LightningToUsbCAdaptor : public ILightningType {
private:
    IUsbCType* mUsbCCharger;
public:
    LightningToUsbCAdaptor(IUsbCType * usbCCharger) : mUsbCCharger(usbCCharger) {}
    void charge() override {
        mUsbCCharger->charge();
    }
    ~LightningToUsbCAdaptor() {
        cout << "Destructing LightningToUsbCAdaptor!" << endl;
    }
};

int main(int argc, char const *argv[])
{
    auto usbCCharger = std::make_unique<UsbCCharger>();
    auto adaptor = std::make_unique<LightningToUsbCAdaptor>(usbCCharger.get());
    auto iphoneX = std::make_unique<IphoneX>();
    iphoneX->setLightningCharger(adaptor.get());
    iphoneX->charge();

    return 0;
}

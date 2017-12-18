#include <iostream>

class Remote;

class Tv
{
    friend class Remote;
public:
    enum {Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, VCR};

    Tv(int s = Off, int mc = 100): state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() { state = (state = On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna ) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? VCR : TV; }
    void settings() const;
    void set_remote_mode(Remote & r);
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};

class Remote
{
    friend class Tv;
private:
    int mode;
    int mode2;
public:
    enum {Normal, Special};

    Remote(int m = Tv::TV): mode(m) {}
    bool volup(Tv & t) { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t) { t.chandown(); }
    void set_chan(Tv & t, int c) { t.channel = c; }
    void set_mode(Tv & t) { t.set_mode(); }
    void set_input(Tv & t) { t.set_input(); }
    void show_mode();
};

bool Tv::volup()
{
    if(volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if(volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if(channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if(channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off ? "Off" : "On") << endl;
    if(state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna ? "antenna" : "cabel") << endl;
        cout << "Input = "
            << (input == TV ? "TV" : "VCR") << endl;
    }
}

void Tv::set_remote_mode(Remote & r)
{
    r.mode2 = r.mode2 == Remote::Normal ? Remote::Special : Remote::Normal;
}

void Remote::show_mode()
{
    using std::cout;
    using std::endl;

    if(mode2 == Normal)
        cout << "remote mode = normal" << endl;
    else
        cout << "remote mode = special" << endl;
}

int main()
{
    Tv s27;
    Remote s72;
    s72.show_mode();
    s27.set_remote_mode(s72);
    s72.show_mode();

    return 0;
}

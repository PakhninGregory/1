#include <iostream>
#include <string>
using namespace std;

class Harbinger
{
private:
    std::string h_name;
    std::string CatchPhrase;
    int h_age;

public:
    Harbinger(std::string name = "Obama", int age = 79, std::string catchPhrase = "Hello there")
        : h_name(name), h_age(age), CatchPhrase(catchPhrase) {}

    std::string getName() const { return h_name; }

    const std::string& getCatchPhrase() const {
        return CatchPhrase;
    }

    void setCatchPhrase(const std::string& catchPhrase) {
        CatchPhrase = catchPhrase;
    }

    int getAge() const { return h_age; }
};

    class Prophet : public Harbinger {
    private:
        std::string MagnumOpus[3];
        std::string ph_name;
        int ph_age;
        std::string ph_call;

    public:
        const std::string* getMagnumOpus() const {
            return MagnumOpus;
        }

        void setMagnumOpus(std::string magnumOpus[]) {
            for (int i = 0; i < 3; ++i) {
                if (magnumOpus[i].length() > 25) { // Проверка на размер
                    std::cout << "Elements are too big! Must be < 25 elements." << std::endl;
                    return;
                }
            }

            for (int i = 0; i < 3; ++i) {
                MagnumOpus[i] = magnumOpus[i];

                if (!ph_call.empty() && ph_call.length() < magnumOpus[i].length()) { // Если ph_call не пустой и элемент больше ph_call, то меняем ph_call
                    ph_call = magnumOpus[i];
                }
            }
        };

        const std::string& getPhName() const {
            return ph_name;
        }

        void setPhName(const std::string& phName) {
            ph_name = phName;
        }

        const std::string& getPhCall() const {
            return ph_call;
        }

        void setPhCall(const std::string& phCall) {
            ph_call = phCall;
        }

        int getPhAge() const {
            return ph_age;
        }

        void setPhAge(int phAge) {
            ph_age = phAge;
        }
};

    class DeusEx : public Prophet {
    //What a shame
    private:
        std::string gd_name;
        int gd_year;

    public:
        DeusEx(const std::string& gdName = "Deus Ex Machina", int gdYear = 2077) : gd_name(gdName), gd_year(gdYear) {
        }

        const std::string& getGdName() const {
            return gd_name;
        }

        int getGdYear() const {
            return gd_year;
        }

        void inTheNameOfGod() {
            printf("%s в возрасте %d говорил, что %s\n", getName().c_str(), getAge(), getCatchPhrase().c_str());
            printf("Первое пророчество: %s\n", getMagnumOpus()[0].c_str());
            printf("Второе пророчество: %s\n", getMagnumOpus()[1].c_str());
            printf("Главное пророчество: %s\n", getPhCall().c_str());
            printf("Так говорил %s в возрасте %d.\n", getPhName().c_str(), getPhAge());
            printf("В год %d пришёл %s, которого предрекали %s и %s.\n", getGdYear(), getGdName().c_str(), getName().c_str(), getPhName().c_str());
        }
};

class Believer : public DeusEx {
private:
    std::string bv_name;
    int bv_age;

public:
    Believer(const std::string& bvName, int bvAge) : bv_name(bvName), bv_age(bvAge), DeusEx() {}

    const std::string& getBvName() const {
        return bv_name;
    }

    void setBvName(const std::string& bvName) {
        bv_name = bvName;
    }

    int getBvAge() const {
        return bv_age;
    }

    void setBvAge(int bvAge) {
        bv_age = bvAge;
    }

    void believerSays() {
        printf("Верующий %s молится %s именем %s. C %d и по сей день.\n", getBvName().c_str(), getGdName().c_str(), getPhName().c_str(), getGdYear());
    }
};
int main()
{
    system("chcp 1251"); 

    Believer believer("Van", 228);
    believer.setCatchPhrase(": \"угабуга\"");

    believer.setPhAge(228);
    believer.setPhCall("ъуъ");
    believer.setPhName("Trump");

    std::string magnumOpus[] = { "First","Second","TRI " };
    believer.setMagnumOpus(magnumOpus);

    believer.inTheNameOfGod();
    cout << endl;
    believer.believerSays();
    return 0;
}
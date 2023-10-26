#ifndef __SETTINGS_H_INCLUDED__
#define __SETTINGS_H_INCLUDED__

#include <QString>
#include <QSettings>
#include <string>
#include "Typedef.h"

class CCSPTSetting
{
public:
	CCSPTSetting(int index);
	CCSPTSetting(int index, QString sSetting);
    ~CCSPTSetting() {}

    void load();
    void store();
    void storePaDac(int gsmProfileDac[], int dcsProfileDac[],
                    float gsmProfileDacPow[], float dcsProfileDacPow[],
                    int gsmDacNum, int gsmDacValue, float gsmPower,
                    int dcsDacNum, int dcsDacvalue, float dcsPower);
    void storePaDac(int gsmProfileDac[], int egsmProfileDac[],int dcsProfileDac[], int pcsProfileDac[],
                    float gsmProfileDacPow[], float egsmProfileDacPow[],float dcsProfileDacPow[], float pcsProfileDacPow[],
                    int gsmDacNum, int gsmDacValue[], float gsmPower[],
                    int egsmDacNum, int egsmDacValue[], float egsmPower[],
                    int dcsDacNum, int dcsDacvalue[], float dcsPower[],
                    int pcsDacNum, int pcsDacvalue[], float pcsPower[]);

private:
    void loadStore();

    void beginTitle(const QString& group);
    void value(const QString& key, std::string& val);
    void value(const QString& key, float& val);
    void value(const QString& key, int& val);
    void value(const QString& key, unsigned int& val);
    void value(const QString &key, bool& val);
    void valueN(const QString& key, float* val, int n);
    void valueN(const QString& key, int* val, int n);
    void valueN(const QString& key, MaxandMin_pclvalue* val, int n);
    void valueN(const QString& key, SwitchSpecture_Select* val, int n);
    void valueN(const QString& key, ModulationSpecture_Select* val, int n);
    void valueN(const QString &key, Coupling_Select* val, int n);
    int mIndex;
    bool mIsLoad;
    QSettings mSetting;
};

#endif

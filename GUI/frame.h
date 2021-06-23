#pragma once
#include "wx/wx.h"

class Frame : public wxFrame {
public:
  Frame();
  ~Frame();
private:
  wxPanel* panelMedien;
  wxRadioBox* rbMedien;
  wxComboBox* listeMedien;
  wxButton* buttonMedienDisplay;
  wxPanel* panelBuch;
  wxPanel* panelCD;
  wxPanel* panelDVD;


  wxPanel* panelPersonen;
  wxPanel* panelVerwaltung;

  wxBoxSizer* sizerVer;
  wxBoxSizer* sizerHor;

  wxMenuBar* menuBar;
  wxMenu* helpMenu;
};

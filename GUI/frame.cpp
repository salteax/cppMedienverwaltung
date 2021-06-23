#include "frame.h"

// DEFINE DINGER BENUTZEN

/* TODO:  panelMedien fertig gestalten
          einzelne Panel mit Labels und InputBoxen bestücken
          EventHandler Medien fertig machen -> funktionen aus alter main importieren vllt. neue cpp Datei mit Funktionen
          Rest fertig gestalten
*/
//g++ gui.cpp frame.cpp `wx-config --libs` `wx-config --cxxflags`

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Medien-Verwaltung", wxPoint(0,0), wxSize(1024,768)) {
  // Menüleiste - Anfang
  menuBar = new wxMenuBar();
  helpMenu = new wxMenu();
  helpMenu->Append(wxID_ABOUT, _T("&About"));
  menuBar->Append(helpMenu, _T("&Help"));
  this->SetMenuBar(menuBar);
  // Menüleiste - Ende

  // Panel Medien - Anfang
  panelMedien = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(520,200));
  panelMedien->SetBackgroundColour(wxColour(0,0,255));

  wxString medienArray[] = {"Buch","CD","DVD"};
  rbMedien = new wxRadioBox(panelMedien, wxID_ANY, "Auswahl des Mediums:", wxPoint(10,10), wxSize(500,40), 3, medienArray);

  listeMedien = new wxComboBox(panelMedien, wxID_ANY, "Liste aller Medien", wxPoint(10,55), wxSize(500,40));
  buttonMedienDisplay = new wxButton(panelMedien, wxID_ANY, "Medium anzeigen.", wxPoint(10,110), wxSize(500,40));

  panelBuch = new wxPanel(panelMedien, wxID_ANY, wxPoint(10,155), wxSize(500,200));
  //panelBuch->Show(false);
  panelBuch->SetBackgroundColour(wxColour(100,50,0));

  panelCD = new wxPanel(panelMedien, wxID_ANY, wxPoint(10,155), wxSize(500,200));
  //panelCD->Show(false);
  panelCD->SetBackgroundColour(wxColour(50,100,0));

  panelDVD = new wxPanel(panelMedien, wxID_ANY, wxPoint(10,155), wxSize(500,200));
  //panelDVD->Show(false);
  panelDVD->SetBackgroundColour(wxColour(50,0,100));
  // Panel Medien - Ende

  // Panel Personen - Anfang
  panelPersonen = new wxPanel(this, wxID_ANY, wxDefaultPosition);
  panelPersonen->SetBackgroundColour(wxColour(0,255,0));
  // Panel Personen - Ende

  // Panel Verwaltung - Anfang
  panelVerwaltung = new wxPanel(this, wxID_ANY, wxDefaultPosition);
  panelVerwaltung->SetBackgroundColour(wxColour(255,0,0));
  // Panel Verwaltung - Ende

  sizerVer = new wxBoxSizer(wxVERTICAL);
  sizerHor = new wxBoxSizer(wxHORIZONTAL);

  sizerVer->Add(panelMedien, 1, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 10);
  sizerVer->Add(panelPersonen, 1, wxEXPAND | wxALL, 10);

  sizerHor->Add(sizerVer, 1, wxEXPAND);
  sizerHor->Add(panelVerwaltung, 1, wxEXPAND | wxTOP | wxBOTTOM | wxRIGHT, 10);

  this->SetSizerAndFit(sizerHor);
}

Frame::~Frame() {

}

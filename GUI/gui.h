#pragma once
#include "wx/wx.h"
#include "frame.h"

class GUI : public wxApp {
public:
  GUI();
  ~GUI();
  virtual bool OnInit();
private:
  Frame* frame = nullptr;
};

#include "gui.h"

wxIMPLEMENT_APP(GUI);

GUI::GUI() {

}

GUI::~GUI() {

}

bool GUI::OnInit() {
  frame = new Frame();
  frame->Show();
  return true;
}

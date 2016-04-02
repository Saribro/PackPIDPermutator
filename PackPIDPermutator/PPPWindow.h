#pragma once

#include "wx/frame.h"

#define ID_PPPWINDOW        10000

#define ID_BUTTON_SELECT    10001
#define ID_BUTTON_UPDATE    10002

#define ID_PACK_FOLDER      10003
#define ID_PACK_NAME        10004

#define ID_CAMERA_PID       10005
#define ID_CAMERA_NAME      10006

#define ID_CHOICE_PID       10007
#define ID_NAME             10008

#define SYMBOL_PPPWINDOW_STYLE      wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)
#define SYMBOL_PPPWINDOW_TITLE      _("Pack PID Permutator")
#define SYMBOL_PPPWINDOW_IDNAME     ID_PPPWINDOW
#define SYMBOL_PPPWINDOW_SIZE       wxSize(400, 300)
#define SYMBOL_PPPWINDOW_POSITION   wxDefaultPosition

class PPPWindow : public wxFrame
{
    DECLARE_CLASS(PPPWindow)

public:
    PPPWindow();
    PPPWindow(wxWindow* parent, wxWindowID id = SYMBOL_PPPWINDOW_IDNAME, const wxString& caption = SYMBOL_PPPWINDOW_TITLE, const wxPoint& pos = SYMBOL_PPPWINDOW_POSITION, const wxSize& size = SYMBOL_PPPWINDOW_SIZE, long style = SYMBOL_PPPWINDOW_STYLE);

    bool Create(wxWindow* parent, wxWindowID id = SYMBOL_PPPWINDOW_IDNAME, const wxString& caption = SYMBOL_PPPWINDOW_TITLE, const wxPoint& pos = SYMBOL_PPPWINDOW_POSITION, const wxSize& size = SYMBOL_PPPWINDOW_SIZE, long style = SYMBOL_PPPWINDOW_STYLE);

    ~PPPWindow() {}

    void Init() {}
    void CreateControls();

    wxBitmap GetBitmapResource(const wxString& name);
    wxIcon   GetIconResource(const wxString& name);

    static bool ShowToolTips() { return true; }
};

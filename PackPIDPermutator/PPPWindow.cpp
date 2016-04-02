#include "PPPWindow.h"
#include "Cameras.h"

#include "wx/bitmap.h"
#include "wx/gbsizer.h"
#include "wx/statbox.h"
#include "wx/stattext.h"
#include "wx/choice.h"
#include "wx/button.h"
#include "wx/panel.h"

IMPLEMENT_CLASS(PPPWindow, wxFrame)

PPPWindow::PPPWindow()
{
    Init();
}

PPPWindow::PPPWindow(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
    Init();
    Create(parent, id, caption, pos, size, style);
}

bool PPPWindow::Create(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
    wxFrame::Create(parent, id, caption, pos, size, style);

    CreateControls();
    Fit();
    Centre();

    return true;
}

void PPPWindow::CreateControls()
{
    auto panelSizer = new wxBoxSizer(wxHORIZONTAL);
    SetSizer(panelSizer);

    auto panel = new wxPanel(this, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    panelSizer->Add(panel, 0, wxGROW, 5);

    auto mainSizer = new wxFlexGridSizer(3, 2, 0, 0);
    panel->SetSizer(mainSizer);

    auto packSizer = new wxStaticBoxSizer(new wxStaticBox(panel, wxID_ANY, _("Calibration Pack")), wxHORIZONTAL);
    packSizer->SetMinSize(wxSize(300, -1));
    mainSizer->Add(packSizer, 0, wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    auto packGridSizer = new wxGridBagSizer(0, 0);
    packGridSizer->SetEmptyCellSize(wxSize(10, 20));
    packSizer->Add(packGridSizer, 0, wxALIGN_CENTER_VERTICAL, 5);

    packGridSizer->Add(new wxStaticText(panel, wxID_STATIC, _("Folder") + ":", wxDefaultPosition, wxDefaultSize, 0),
                       wxGBPosition(0, 0), wxGBSpan(1, 1), wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    packGridSizer->Add(new wxStaticText(panel, wxID_STATIC, _("Name") + ":", wxDefaultPosition, wxDefaultSize, 0),
                       wxGBPosition(1, 0), wxGBSpan(1, 1), wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    packGridSizer->Add(new wxStaticText(panel, ID_PACK_FOLDER, "", wxDefaultPosition, wxDefaultSize, 0),
                       wxGBPosition(0, 1), wxGBSpan(1, 1), wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    packGridSizer->Add(new wxStaticText(panel, ID_PACK_NAME, "", wxDefaultPosition, wxDefaultSize, 0),
                       wxGBPosition(1, 1), wxGBSpan(1, 1), wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    mainSizer->Add(new wxButton(panel, ID_BUTTON_SELECT, _("Select"), wxDefaultPosition, wxDefaultSize, 0),
                   0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    auto cameraSizer = new wxStaticBoxSizer(new wxStaticBox(panel, wxID_STATIC, _("Camera")), wxHORIZONTAL);
    mainSizer->Add(cameraSizer, 0, wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    auto cameraGridSizer = new wxGridBagSizer(0, 0);
    cameraGridSizer->SetEmptyCellSize(wxSize(10, 20));
    cameraSizer->Add(cameraGridSizer, 0, wxALIGN_CENTER_VERTICAL, 5);

    cameraGridSizer->Add(new wxStaticText(panel, wxID_STATIC, _("PID") + ":", wxDefaultPosition, wxDefaultSize, 0),
                         wxGBPosition(0, 0), wxGBSpan(1, 1), wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    cameraGridSizer->Add(new wxStaticText(panel, wxID_STATIC, _("Name") + ":", wxDefaultPosition, wxDefaultSize, 0),
                         wxGBPosition(1, 0), wxGBSpan(1, 1), wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    cameraGridSizer->Add(new wxStaticText(panel, ID_CAMERA_PID, "", wxDefaultPosition, wxDefaultSize, 0),
                         wxGBPosition(0, 1), wxGBSpan(1, 1), wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    cameraGridSizer->Add(new wxStaticText(panel, ID_CAMERA_NAME, "", wxDefaultPosition, wxDefaultSize, 0),
                         wxGBPosition(1, 1), wxGBSpan(1, 1), wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    mainSizer->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    auto updateSizer = new wxStaticBoxSizer(new wxStaticBox(panel, wxID_STATIC, _("Update")), wxHORIZONTAL);
    mainSizer->Add(updateSizer, 0, wxGROW | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    auto updateGridSizer = new wxGridBagSizer(0, 0);
    updateGridSizer->SetEmptyCellSize(wxSize(10, 20));
    updateSizer->Add(updateGridSizer, 0, wxALIGN_CENTER_VERTICAL, 5);

    updateGridSizer->Add(new wxStaticText(panel, wxID_STATIC, _("PID") + ":", wxDefaultPosition, wxDefaultSize, 0),
                         wxGBPosition(0, 0), wxGBSpan(1, 1), wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    updateGridSizer->Add(new wxStaticText(panel, wxID_STATIC, _("Name") + ":", wxDefaultPosition, wxDefaultSize, 0),
                         wxGBPosition(1, 0), wxGBSpan(1, 1), wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    wxArrayString cameraPIDList;
    for(auto const & pid : cameras) cameraPIDList.Add(pid.first);

    auto PIDChoice = new wxChoice(panel, ID_CHOICE_PID, wxDefaultPosition, wxDefaultSize, cameraPIDList, 0);
    PIDChoice->Disable();
    updateGridSizer->Add(PIDChoice, wxGBPosition(0, 1), wxGBSpan(1, 1), wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    updateGridSizer->Add(new wxStaticText(panel, ID_NAME, "", wxDefaultPosition, wxDefaultSize, 0),
                         wxGBPosition(1, 1), wxGBSpan(1, 1), wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL, 5);

    auto updateButton = new wxButton(panel, ID_BUTTON_UPDATE, _("Update"), wxDefaultPosition, wxDefaultSize, 0);
    updateButton->Disable();
    mainSizer->Add(updateButton, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, 5);
}

wxBitmap PPPWindow::GetBitmapResource(const wxString& name)
{
    wxUnusedVar(name);
    return wxNullBitmap;
}

wxIcon PPPWindow::GetIconResource(const wxString& name)
{
    wxUnusedVar(name);
    return wxNullIcon;
}

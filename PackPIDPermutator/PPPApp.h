#pragma once

#include "wx/app.h"
#include "wx/filename.h"

class PackPIDPermutatorApp : public wxApp
{
    DECLARE_CLASS(PackPIDPermutatorApp)

public:
    PackPIDPermutatorApp();

    void Init();

    virtual bool OnInit();
    virtual int  OnExit() { return wxApp::OnExit(); }

private:
    void OnButtonSelectClick(wxCommandEvent &)      { SelectPack(); }
    void OnButtonUpdateClick(wxCommandEvent &)      { UpdatePack(); }
    void OnChoicePIDSelect(wxCommandEvent & event)  { SetNameForPID(event.GetString()); }

    void SelectPack();
    void UpdatePack();
    void SetNameForPID(wxString const & PID);

    bool ReadPID(std::wstring & status);
    bool WritePID(std::wstring & status);

    wxFileName mPackLocation;
};

DECLARE_APP(PackPIDPermutatorApp)

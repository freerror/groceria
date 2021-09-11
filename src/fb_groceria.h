///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Jun 19 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class frameMain
///////////////////////////////////////////////////////////////////////////////
class frameMain : public wxFrame
{
	private:

	protected:
		wxNotebook* notebookTabHolder;
		wxPanel* panelGroceryList;
		wxListBox* listBoxRecipeChooser;
		wxListBox* listBoxRestockChooser;
		wxButton* buttonSelectRecipeChooser;
		wxButton* buttonRemoveRecipeChooser;
		wxButton* buttonRemoveCopiesRecipeChooser;
		wxButton* buttonSelectIngredChooser;
		wxButton* buttonRemoveIngredChooser;
		wxButton* buttonRemoveCopiesIngredChooser;
		wxListBox* listBoxRecipeChoices;
		wxListBox* listBoxRestockChoices;
		wxButton* buttonClear;
		wxButton* buttonGenerate;
		wxPanel* panelIngredients;
		wxListBox* listBoxIngredients;
		wxStaticText* staticTextLabelIngredIsle;
		wxComboBox* comboBoxIngredIsle;
		wxStaticText* staticTextLabelIngredName;
		wxTextCtrl* textCtrlIngredName;
		wxButton* buttonIngredSave;
		wxButton* buttonIngredDelete;
		wxPanel* panelRecipes;
		wxListBox* listBoxRecipes;
		wxStaticText* staticTextLabelRecCategory;
		wxComboBox* comboBoxReciCategory;
		wxStaticText* staticTextLabelRecName;
		wxTextCtrl* textCtrlReciName;
		wxStaticText* staticTextLabelRecIngreds;
		wxListBox* listBoxRecAvailIngreds;
		wxListBox* listBoxRecChosenIngreds;
		wxButton* buttonRecSave;
		wxButton* buttonRecDelete;

		// Virtual event handlers, override them in your derived class
		virtual void frameMainOnShow( wxShowEvent& event ) { event.Skip(); }
		virtual void listBoxRecipeChooserOnListBoxDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void listBoxRestockChooserOnListBoxDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonSelectRecipeChooserOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonRemoveRecipeChooserOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonRemoveCopiesRecipeChooserOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonSelectIngredChooserOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonRemoveIngredChooserOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonRemoveCopiesIngredChooserOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void listBoxRecipeChoicesOnListBoxDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void listBoxRestockChoicesOnListBoxDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonClearOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonGenerateOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void listBoxIngredientsOnListBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonIngredSaveOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonIngredDeleteOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void listBoxRecipesOnListBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void listBoxRecAvailIngredsOnListBoxDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void listBoxRecChosenIngredsOnListBoxDClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonRecSaveOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void buttonRecDeleteOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		frameMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Groceria - Recipe to Grocery List Generator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxBORDER_THEME|wxTAB_TRAVERSAL );

		~frameMain();

};

///////////////////////////////////////////////////////////////////////////////
/// Class frameGroceryOutput
///////////////////////////////////////////////////////////////////////////////
class frameGroceryOutput : public wxFrame
{
	private:

	protected:
		wxTextCtrl* textCtrlGroceryOutput;
		wxStdDialogButtonSizer* sdbSizerGroceryOutput;
		wxButton* sdbSizerGroceryOutputOK;

		// Virtual event handlers, override them in your derived class
		virtual void frameGroceryOutputOnShow( wxShowEvent& event ) { event.Skip(); }
		virtual void sdbSizerGroceryOutputOnOKButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		frameGroceryOutput( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 200,950 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~frameGroceryOutput();

};


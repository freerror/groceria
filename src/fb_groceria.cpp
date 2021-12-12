///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "fb_groceria.h"

///////////////////////////////////////////////////////////////////////////

frameMain::frameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 950,950 ), wxDefaultSize );

	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );

	notebookTabHolder = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	notebookTabHolder->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	notebookTabHolder->SetBackgroundColour( wxColour( 189, 154, 194 ) );

	panelGroceryList = new wxPanel( notebookTabHolder, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME|wxTAB_TRAVERSAL );
	panelGroceryList->SetForegroundColour( wxColour( 243, 209, 220 ) );
	panelGroceryList->SetBackgroundColour( wxColour( 243, 209, 220 ) );

	wxBoxSizer* bSizerGroceryList;
	bSizerGroceryList = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerGroceryListTop;
	bSizerGroceryListTop = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerGroceryListTopLists;
	bSizerGroceryListTopLists = new wxBoxSizer( wxHORIZONTAL );

	listBoxRecipeChooser = new wxListBox( panelGroceryList, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerGroceryListTopLists->Add( listBoxRecipeChooser, 1, wxALL|wxEXPAND, 5 );

	listBoxRestockChooser = new wxListBox( panelGroceryList, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerGroceryListTopLists->Add( listBoxRestockChooser, 1, wxALL|wxEXPAND, 5 );


	bSizerGroceryListTop->Add( bSizerGroceryListTopLists, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerTfrBtns;
	bSizerTfrBtns = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizerTfrBtnsLeft;
	bSizerTfrBtnsLeft = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerTfrBtnsLeftBtns;
	bSizerTfrBtnsLeftBtns = new wxBoxSizer( wxHORIZONTAL );

	buttonSelectRecipeChooser = new wxButton( panelGroceryList, wxID_ANY, wxT("Select Recipe"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTfrBtnsLeftBtns->Add( buttonSelectRecipeChooser, 0, wxALL, 5 );

	buttonRemoveRecipeChooser = new wxButton( panelGroceryList, wxID_ANY, wxT("Remove Recipe"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTfrBtnsLeftBtns->Add( buttonRemoveRecipeChooser, 0, wxALL, 5 );

	buttonRemoveCopiesRecipeChooser = new wxButton( panelGroceryList, wxID_ANY, wxT("Remove Copies"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTfrBtnsLeftBtns->Add( buttonRemoveCopiesRecipeChooser, 0, wxALL, 5 );


	bSizerTfrBtnsLeft->Add( bSizerTfrBtnsLeftBtns, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );


	bSizerTfrBtns->Add( bSizerTfrBtnsLeft, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerTfrBtnsRight;
	bSizerTfrBtnsRight = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerTfrBtnsRightBtns;
	bSizerTfrBtnsRightBtns = new wxBoxSizer( wxHORIZONTAL );

	buttonSelectIngredChooser = new wxButton( panelGroceryList, wxID_ANY, wxT("Select Ingredient"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTfrBtnsRightBtns->Add( buttonSelectIngredChooser, 0, wxALL, 5 );

	buttonRemoveIngredChooser = new wxButton( panelGroceryList, wxID_ANY, wxT("Remove Ingredient"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTfrBtnsRightBtns->Add( buttonRemoveIngredChooser, 0, wxALL, 5 );

	buttonRemoveCopiesIngredChooser = new wxButton( panelGroceryList, wxID_ANY, wxT("Remove Copies"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerTfrBtnsRightBtns->Add( buttonRemoveCopiesIngredChooser, 0, wxALL, 5 );


	bSizerTfrBtnsRight->Add( bSizerTfrBtnsRightBtns, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );


	bSizerTfrBtns->Add( bSizerTfrBtnsRight, 1, wxEXPAND, 5 );


	bSizerGroceryListTop->Add( bSizerTfrBtns, 0, wxALL|wxEXPAND, 0 );

	wxBoxSizer* bSizerGroceryListBtmLists;
	bSizerGroceryListBtmLists = new wxBoxSizer( wxHORIZONTAL );

	listBoxRecipeChoices = new wxListBox( panelGroceryList, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerGroceryListBtmLists->Add( listBoxRecipeChoices, 1, wxALL|wxEXPAND, 5 );

	listBoxRestockChoices = new wxListBox( panelGroceryList, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerGroceryListBtmLists->Add( listBoxRestockChoices, 1, wxALL|wxEXPAND, 5 );


	bSizerGroceryListTop->Add( bSizerGroceryListBtmLists, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerGroceryListBtm;
	bSizerGroceryListBtm = new wxBoxSizer( wxHORIZONTAL );

	buttonClear = new wxButton( panelGroceryList, wxID_ANY, wxT("Clear All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerGroceryListBtm->Add( buttonClear, 0, wxALL, 0 );


	bSizerGroceryListBtm->Add( 50, 0, 1, wxEXPAND, 0 );

	buttonGenerate = new wxButton( panelGroceryList, wxID_ANY, wxT("Generate Grocery List"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerGroceryListBtm->Add( buttonGenerate, 0, wxALL, 0 );


	bSizerGroceryListTop->Add( bSizerGroceryListBtm, 0, wxALL|wxEXPAND, 5 );


	bSizerGroceryList->Add( bSizerGroceryListTop, 1, wxALL|wxEXPAND, 5 );


	panelGroceryList->SetSizer( bSizerGroceryList );
	panelGroceryList->Layout();
	bSizerGroceryList->Fit( panelGroceryList );
	notebookTabHolder->AddPage( panelGroceryList, wxT("Grocery List"), true );
	panelIngredients = new wxPanel( notebookTabHolder, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelIngredients->SetBackgroundColour( wxColour( 243, 209, 220 ) );

	wxBoxSizer* bSizerIngredients;
	bSizerIngredients = new wxBoxSizer( wxHORIZONTAL );

	listBoxIngredients = new wxListBox( panelIngredients, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerIngredients->Add( listBoxIngredients, 2, wxALL|wxEXPAND, 10 );

	wxBoxSizer* bSizerIngredientsForm;
	bSizerIngredientsForm = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerIngredFormRow3;
	bSizerIngredFormRow3 = new wxBoxSizer( wxHORIZONTAL );

	staticTextLabelIngredIsle = new wxStaticText( panelIngredients, wxID_ANY, wxT("Aisle"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	staticTextLabelIngredIsle->Wrap( -1 );
	bSizerIngredFormRow3->Add( staticTextLabelIngredIsle, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	comboBoxIngredIsle = new wxComboBox( panelIngredients, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerIngredFormRow3->Add( comboBoxIngredIsle, 1, wxALL, 5 );


	bSizerIngredientsForm->Add( bSizerIngredFormRow3, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizerIngredFormRow4;
	bSizerIngredFormRow4 = new wxBoxSizer( wxHORIZONTAL );

	staticTextLabelIngredName = new wxStaticText( panelIngredients, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	staticTextLabelIngredName->Wrap( -1 );
	bSizerIngredFormRow4->Add( staticTextLabelIngredName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	textCtrlIngredName = new wxTextCtrl( panelIngredients, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerIngredFormRow4->Add( textCtrlIngredName, 1, wxALL, 5 );


	bSizerIngredientsForm->Add( bSizerIngredFormRow4, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizerIngredFormRow41;
	bSizerIngredFormRow41 = new wxBoxSizer( wxVERTICAL );

	buttonIngredSave = new wxButton( panelIngredients, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerIngredFormRow41->Add( buttonIngredSave, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizerIngredFormRow41->Add( 0, 0, 1, wxEXPAND, 5 );

	buttonIngredDelete = new wxButton( panelIngredients, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerIngredFormRow41->Add( buttonIngredDelete, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizerIngredientsForm->Add( bSizerIngredFormRow41, 1, wxALL|wxEXPAND, 5 );


	bSizerIngredients->Add( bSizerIngredientsForm, 3, wxALL|wxEXPAND, 15 );


	panelIngredients->SetSizer( bSizerIngredients );
	panelIngredients->Layout();
	bSizerIngredients->Fit( panelIngredients );
	notebookTabHolder->AddPage( panelIngredients, wxT("Ingredients"), false );
	panelRecipes = new wxPanel( notebookTabHolder, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	panelRecipes->SetBackgroundColour( wxColour( 243, 209, 220 ) );

	wxBoxSizer* bSizerRecipes;
	bSizerRecipes = new wxBoxSizer( wxHORIZONTAL );

	listBoxRecipes = new wxListBox( panelRecipes, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerRecipes->Add( listBoxRecipes, 2, wxALL|wxEXPAND, 10 );

	wxBoxSizer* bSizerRecipesForm1;
	bSizerRecipesForm1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerRecFormRow3;
	bSizerRecFormRow3 = new wxBoxSizer( wxHORIZONTAL );

	staticTextLabelRecName = new wxStaticText( panelRecipes, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	staticTextLabelRecName->Wrap( -1 );
	bSizerRecFormRow3->Add( staticTextLabelRecName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	textCtrlReciName = new wxTextCtrl( panelRecipes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerRecFormRow3->Add( textCtrlReciName, 1, wxALL, 5 );


	bSizerRecipesForm1->Add( bSizerRecFormRow3, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizerRecFormRow4;
	bSizerRecFormRow4 = new wxBoxSizer( wxVERTICAL );

	staticTextLabelRecIngreds = new wxStaticText( panelRecipes, wxID_ANY, wxT("Ingredients"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	staticTextLabelRecIngreds->Wrap( -1 );
	bSizerRecFormRow4->Add( staticTextLabelRecIngreds, 0, wxALL, 5 );

	wxBoxSizer* bSizerRecFormIngreds;
	bSizerRecFormIngreds = new wxBoxSizer( wxHORIZONTAL );

	listBoxRecAvailIngreds = new wxListBox( panelRecipes, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerRecFormIngreds->Add( listBoxRecAvailIngreds, 1, wxALL|wxEXPAND, 5 );

	listBoxRecChosenIngreds = new wxListBox( panelRecipes, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerRecFormIngreds->Add( listBoxRecChosenIngreds, 1, wxALL|wxEXPAND, 5 );


	bSizerRecFormRow4->Add( bSizerRecFormIngreds, 1, wxEXPAND, 5 );


	bSizerRecipesForm1->Add( bSizerRecFormRow4, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizerRecFormRow5;
	bSizerRecFormRow5 = new wxBoxSizer( wxVERTICAL );

	buttonRecSave = new wxButton( panelRecipes, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerRecFormRow5->Add( buttonRecSave, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizerRecFormRow5->Add( 0, 0, 1, wxEXPAND, 5 );

	buttonRecDelete = new wxButton( panelRecipes, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerRecFormRow5->Add( buttonRecDelete, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizerRecipesForm1->Add( bSizerRecFormRow5, 1, wxALL|wxEXPAND, 5 );


	bSizerRecipes->Add( bSizerRecipesForm1, 3, wxALL|wxEXPAND, 15 );


	panelRecipes->SetSizer( bSizerRecipes );
	panelRecipes->Layout();
	bSizerRecipes->Fit( panelRecipes );
	notebookTabHolder->AddPage( panelRecipes, wxT("Recipes"), false );

	bSizerMain->Add( notebookTabHolder, 1, wxEXPAND | wxALL, 0 );


	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_SHOW, wxShowEventHandler( frameMain::frameMainOnShow ) );
	listBoxRecipeChooser->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecipeChooserOnListBoxDClick ), NULL, this );
	listBoxRestockChooser->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRestockChooserOnListBoxDClick ), NULL, this );
	buttonSelectRecipeChooser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonSelectRecipeChooserOnButtonClick ), NULL, this );
	buttonRemoveRecipeChooser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveRecipeChooserOnButtonClick ), NULL, this );
	buttonRemoveCopiesRecipeChooser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveCopiesRecipeChooserOnButtonClick ), NULL, this );
	buttonSelectIngredChooser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonSelectIngredChooserOnButtonClick ), NULL, this );
	buttonRemoveIngredChooser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveIngredChooserOnButtonClick ), NULL, this );
	buttonRemoveCopiesIngredChooser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveCopiesIngredChooserOnButtonClick ), NULL, this );
	listBoxRecipeChoices->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecipeChoicesOnListBoxDClick ), NULL, this );
	listBoxRestockChoices->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRestockChoicesOnListBoxDClick ), NULL, this );
	buttonClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonClearOnButtonClick ), NULL, this );
	buttonGenerate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonGenerateOnButtonClick ), NULL, this );
	listBoxIngredients->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( frameMain::listBoxIngredientsOnListBox ), NULL, this );
	listBoxIngredients->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxIngredientsOnListBoxDClick ), NULL, this );
	buttonIngredSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonIngredSaveOnButtonClick ), NULL, this );
	buttonIngredDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonIngredDeleteOnButtonClick ), NULL, this );
	listBoxRecipes->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( frameMain::listBoxRecipesOnListBox ), NULL, this );
	listBoxRecipes->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecipesOnListBoxDClick ), NULL, this );
	listBoxRecAvailIngreds->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecAvailIngredsOnListBoxDClick ), NULL, this );
	listBoxRecChosenIngreds->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecChosenIngredsOnListBoxDClick ), NULL, this );
	buttonRecSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRecSaveOnButtonClick ), NULL, this );
	buttonRecDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRecDeleteOnButtonClick ), NULL, this );
}

frameMain::~frameMain()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SHOW, wxShowEventHandler( frameMain::frameMainOnShow ) );
	listBoxRecipeChooser->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecipeChooserOnListBoxDClick ), NULL, this );
	listBoxRestockChooser->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRestockChooserOnListBoxDClick ), NULL, this );
	buttonSelectRecipeChooser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonSelectRecipeChooserOnButtonClick ), NULL, this );
	buttonRemoveRecipeChooser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveRecipeChooserOnButtonClick ), NULL, this );
	buttonRemoveCopiesRecipeChooser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveCopiesRecipeChooserOnButtonClick ), NULL, this );
	buttonSelectIngredChooser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonSelectIngredChooserOnButtonClick ), NULL, this );
	buttonRemoveIngredChooser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveIngredChooserOnButtonClick ), NULL, this );
	buttonRemoveCopiesIngredChooser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRemoveCopiesIngredChooserOnButtonClick ), NULL, this );
	listBoxRecipeChoices->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecipeChoicesOnListBoxDClick ), NULL, this );
	listBoxRestockChoices->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRestockChoicesOnListBoxDClick ), NULL, this );
	buttonClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonClearOnButtonClick ), NULL, this );
	buttonGenerate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonGenerateOnButtonClick ), NULL, this );
	listBoxIngredients->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( frameMain::listBoxIngredientsOnListBox ), NULL, this );
	listBoxIngredients->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxIngredientsOnListBoxDClick ), NULL, this );
	buttonIngredSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonIngredSaveOnButtonClick ), NULL, this );
	buttonIngredDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonIngredDeleteOnButtonClick ), NULL, this );
	listBoxRecipes->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( frameMain::listBoxRecipesOnListBox ), NULL, this );
	listBoxRecipes->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecipesOnListBoxDClick ), NULL, this );
	listBoxRecAvailIngreds->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecAvailIngredsOnListBoxDClick ), NULL, this );
	listBoxRecChosenIngreds->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frameMain::listBoxRecChosenIngredsOnListBoxDClick ), NULL, this );
	buttonRecSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRecSaveOnButtonClick ), NULL, this );
	buttonRecDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::buttonRecDeleteOnButtonClick ), NULL, this );

}

frameGroceryOutput::frameGroceryOutput( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,950 ), wxDefaultSize );

	wxBoxSizer* bSizerGroceryOutput;
	bSizerGroceryOutput = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerframeGroceryOutput;
	bSizerframeGroceryOutput = new wxBoxSizer( wxVERTICAL );

	textCtrlGroceryOutput = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizerframeGroceryOutput->Add( textCtrlGroceryOutput, 1, wxALL|wxEXPAND, 5 );


	bSizerGroceryOutput->Add( bSizerframeGroceryOutput, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerGroceryOutputStd;
	bSizerGroceryOutputStd = new wxBoxSizer( wxHORIZONTAL );

	sdbSizerGroceryOutput = new wxStdDialogButtonSizer();
	sdbSizerGroceryOutputOK = new wxButton( this, wxID_OK );
	sdbSizerGroceryOutput->AddButton( sdbSizerGroceryOutputOK );
	sdbSizerGroceryOutput->Realize();

	bSizerGroceryOutputStd->Add( sdbSizerGroceryOutput, 1, wxALIGN_BOTTOM|wxALL, 10 );


	bSizerGroceryOutput->Add( bSizerGroceryOutputStd, 0, wxEXPAND, 5 );


	this->SetSizer( bSizerGroceryOutput );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_SHOW, wxShowEventHandler( frameGroceryOutput::frameGroceryOutputOnShow ) );
	sdbSizerGroceryOutputOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameGroceryOutput::sdbSizerGroceryOutputOnOKButtonClick ), NULL, this );
}

frameGroceryOutput::~frameGroceryOutput()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SHOW, wxShowEventHandler( frameGroceryOutput::frameGroceryOutputOnShow ) );
	sdbSizerGroceryOutputOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameGroceryOutput::sdbSizerGroceryOutputOnOKButtonClick ), NULL, this );

}

/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * saesguibase
 * Copyright (C)  2011 <>
 * 
 * saesguibase is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * saesguibase is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _BARCODE_DIAGNOSIS_FUNCTIONALITY_H_
#define _BARCODE_DIAGNOSIS_FUNCTIONALITY_H_

#include <gtkmm.h>
#include <iostream>
#include <string.h>
#include <Functionalities/graphic-display-functionality.h>
#include "Gui/Widgets/bar-code-diagnosis-widget.h"
#include <Log/ISMTTLog.h>

namespace Smartmatic
{
	namespace SAES
	{
		namespace GUI
		{
			namespace Functionality
			{
				class BarcodeDiagnosisFunctionality: public GraphicDisplayFunctionality<Smartmatic::Functionality::MenuOptionDescriptor>
				{

				public:

					/**
					 * @brief	Gets the dont allow help.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	true if it succeeds, false if it fails.
					 */

					bool DontAllowHelp();

					/**
					 * @brief	Gets the help sequence key.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	The help sequence key.
					 */

					std::vector<Smartmatic::GUI::Widgets::KeysActionsCode> getHelpSeqKey();

					/**
					 * @brief	Gets the dont allow exit.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	true if it succeeds, false if it fails.
					 */

					bool DontAllowExit();

					/**
					 * @brief	Gets the sequence key.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	The sequence key.
					 */

					std::vector<Smartmatic::GUI::Widgets::KeysActionsCode> getSeqKey();

					/**
					 * @brief	Gets the current.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	null if it fails, else.
					 */

					static BarcodeDiagnosisFunctionality* Current();

				protected:

					/**
					 * @brief	Gets the logger.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	null if it fails, else the logger.
					 */

					Smartmatic::Log::ISMTTLog* getLogger();

					/**
					 * @brief	Gets the start log message.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	The start log message.
					 */

					Glib::ustring getStartLogMessage();

					/**
					 * @brief	Gets the finish log message.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	The finish log message.
					 */

					Glib::ustring getFinishLogMessage();

					/**
					 * @brief virtual method delete all element
					 * @date 03/04/2012
					 * @author Yadickson Soto
					 */
					virtual void deleteElement();

				private:
					void on_printing_signal(bool isPrinting);

					static BarcodeDiagnosisFunctionality *current_instance; ///< The current instance

					/**
					 * @brief	Default constructor.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 */

					BarcodeDiagnosisFunctionality();

					/**
					 * @brief	Finaliser.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 */

					~BarcodeDiagnosisFunctionality();			

					/**
					 * @brief	Dispose of this object, cleaning up any resources it uses.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 */

					void Dispose();

					/**
					 * @brief	Initializes this object.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 */

					void Initialize();

					/**
					 * @brief	Gets the frame.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	null if it fails, else the frame.
					 */

					Gtk::Widget* GetFrame();

					Smartmatic::SAES::GUI::Widgets::BarCodeDiagnosisWidget* readerWidget;   ///< The reader widget

					/**
					 * @brief	Gets the window title.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	The window title.
					 */

					std::string GetWindowTitle();

					/**
					 * @brief	Gets the menu option type.
					 *
					 * @author	Luiggi.mendez
					 * @date	28/04/2011
					 *
					 * @return	The menu option type.
					 */

					Smartmatic::Functionality::MenuOptionDescriptor GetMenuOptionType();	

					sigc::connection connBCDiag;	///< connection barcode diagnosis
					void on_BCDiagFinished();
					static Smartmatic::Log::ISMTTLog* logger; /**<logger*/  ///< The logger
				};
			}
		}
	}
}


#endif // _BARCODE_DIAGNOSIS_FUNCTIONALITY_H_

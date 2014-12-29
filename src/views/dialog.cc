/*
 * *****************************************************************************
 *   Copyright 2014 Spectra Logic Corporation. All Rights Reserved.
 *   Licensed under the Apache License, Version 2.0 (the "License"). You may not
 *   use this file except in compliance with the License. A copy of the License
 *   is located at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *   or in the "license" file accompanying this file.
 *   This file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 *   CONDITIONS OF ANY KIND, either express or implied. See the License for the
 *   specific language governing permissions and limitations under the License.
 * *****************************************************************************
 */

#include <QPushButton>
#include "views/dialog.h"

Dialog::Dialog(QWidget* parent)
	: QDialog(parent),
	  m_layout(new QVBoxLayout),
	  m_form(new QGridLayout),
	  m_baseErrorLabel(NULL)
{
	m_buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
					   | QDialogButtonBox::Cancel);
	connect(m_buttonBox, SIGNAL(accepted()), this, SLOT(Accept()));
	connect(m_buttonBox, SIGNAL(rejected()), this, SLOT(Reject()));

	m_layout->addLayout(m_form);
	m_layout->addWidget(m_buttonBox);
	setLayout(m_layout);
}

Dialog::~Dialog()
{
}

void
Dialog::Reject()
{
	reject();
}

void
Dialog::EnableOKButton()
{
	QPushButton* button = m_buttonBox->button(QDialogButtonBox::Ok);
	button->setEnabled(true);
}

void
Dialog::DisableOKButton()
{
	QPushButton* button = m_buttonBox->button(QDialogButtonBox::Ok);
	button->setEnabled(false);
}

bool
Dialog::ValidateLineEditNotEmpty(QLabel* label,
				 QLineEdit* lineEdit,
				 QLabel* errorLabel)
{
	bool valid = true;
	if (lineEdit->text().trimmed().isEmpty()) {
		label->setStyleSheet("QLabel { color: red; }");
		errorLabel->setText("cannot be blank");
		valid = false;
	} else {
		label->setStyleSheet("");
		errorLabel->setText("");
	}
	return valid;
}

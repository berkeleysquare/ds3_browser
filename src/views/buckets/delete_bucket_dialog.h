/*
 * *****************************************************************************
 *   Copyright 2014-2015 Spectra Logic Corporation. All Rights Reserved.
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

#ifndef DELETE_BUCKET_DIALOG_H
#define DELETE_BUCKET_DIALOG_H

#include <QString>

#include "views/ds3_delete_dialog.h"

// A DS3DeleteDialog for deleting buckets.  Since the AWS delete bucket
// API only supports deleting empty buckets, the user is not forced
// to type in the confirmation word.  If we ever support deleting non-empty
// buckets, this dialog should be changed to require the confirmation.
class DeleteBucketDialog : public DS3DeleteDialog
{
public:
	DeleteBucketDialog(Client* client,
			   const QString& bucketName,
			   QWidget* parent = 0);

protected:
	bool Delete();
};

#endif

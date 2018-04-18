.. -*- rst -*-

Backups (backups)
=================

A backup is a full copy of a volume stored in an external service.
The service can be configured. The only supported service is Object
Storage. A backup can subsequently be restored from the external
service to either the same volume that the backup was originally
taken from or to a new volume. Backup and restore operations can
only be carried out on volumes that are in an unattached and
available state.

When you create, list, or delete backups, these status values are
possible:

**Backup statuses**

+-----------------+---------------------------------------------+
| Status          | Description                                 |
+-----------------+---------------------------------------------+
| creating        | The backup is being created.                |
+-----------------+---------------------------------------------+
| available       | The backup is ready to restore to a volume. |
+-----------------+---------------------------------------------+
| deleting        | The backup is being deleted.                |
+-----------------+---------------------------------------------+
| error           | A backup error occurred.                    |
+-----------------+---------------------------------------------+
| restoring       | The backup is being restored to a volume.   |
+-----------------+---------------------------------------------+
| error_restoring | A backup restoration error occurred.        |
+-----------------+---------------------------------------------+


If an error occurs, you can find more information about the error
in the ``fail_reason`` field for the backup.


List backups with detail
~~~~~~~~~~~~~~~~~~~~~~~~

.. rest_method::  GET /v3/{project_id}/backups/detail

Lists Block Storage backups, with details, to which the project has access,
since v3.31 if non-admin users specify invalid filters in the url,
API will return bad request.


Normal response codes: 200

Error response codes: badRequest(400)


Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - all_tenants: all-tenants
   - sort: sort
   - limit: limit
   - offset: offset
   - marker: marker
   - with_count: with_count


Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - backups: backups
   - status: status_4
   - object_count: object_count
   - fail_reason: fail_reason
   - description: description
   - links: links_1
   - availability_zone: availability_zone
   - created_at: created_at
   - updated_at: updated_at
   - name: name_1
   - has_dependent_backups: has_dependent_backups
   - volume_id: volume_id
   - container: container
   - size: size
   - id: id_1
   - is_incremental: is_incremental
   - data_timestamp: data_timestamp
   - snapshot_id: snapshot_id_2
   - os-backup-project-attr:project_id: os-backup-project-attr:project_id
   - count: count

Response Example
----------------

.. literalinclude:: ./samples/backups-list-detailed-response.json
   :language: javascript


Show backup detail
~~~~~~~~~~~~~~~~~~

.. rest_method::  GET /v3/{project_id}/backups/{backup_id}

Shows details for a backup.


Normal response codes: 200


Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - backup_id: backup_id


Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - backup: backup
   - status: status_4
   - object_count: object_count
   - container: container
   - description: description
   - links: links_1
   - availability_zone: availability_zone
   - created_at: created_at
   - updated_at: updated_at
   - name: name_1
   - has_dependent_backups: has_dependent_backups
   - volume_id: volume_id
   - fail_reason: fail_reason
   - size: size
   - backup: backup
   - id: id_1
   - is_incremental: is_incremental
   - data_timestamp: data_timestamp
   - snapshot_id: snapshot_id_2
   - os-backup-project-attr:project_id: os-backup-project-attr:project_id

Response Example
----------------

.. literalinclude:: ./samples/backup-show-response.json
   :language: javascript


Delete a backup
~~~~~~~~~~~~~~~

.. rest_method::  DELETE /v3/{project_id}/backups/{backup_id}

Deletes a backup.

Normal response codes: 202

Error response codes: Bad Request(400)

Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - backup_id: backup_id


Restore a backup
~~~~~~~~~~~~~~~~

.. rest_method::  POST /v3/{project_id}/backups/{backup_id}/restore

Restores a Block Storage backup to an existing or new Block Storage volume.

The name parameter will work only if a new volume is created.

If UUID is specified, the backup will be restored to the specified volume.

If no existing volume UUID is provided, the backup will be restored to a
new volume matching the size and name of the originally backed up volume.
In this case, if the name parameter is provided, it will be used as the
name of the new volume.

Normal response codes: 202

Error response codes: Bad Request(400), Request Entity Too Large(413)


Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - backup_id: backup_id
   - restore: restore
   - name: name_8
   - volume_id: volume_id_6

Request Example
---------------

.. literalinclude:: ./samples/backup-restore-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - restore: restore
   - backup_id: backup_id
   - volume_id: volume_id
   - volume_name: volume_name

Response Example
----------------

.. literalinclude:: ./samples/backup-restore-response.json
   :language: javascript

Create a backup
~~~~~~~~~~~~~~~

.. rest_method::  POST /v3/{project_id}/backups

Creates a Block Storage backup from a volume.

Normal response codes: 202

Error response codes: Bad Request(400), Internal Server Error(500)

Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - backup: backup
   - volume_id: volume_id_2
   - container: container
   - description: description
   - incremental: incremental
   - force: force
   - name: name_optional
   - snapshot_id: snapshot_id_3
   - metadata: metadata_9

Request Example
---------------

.. literalinclude:: ./samples/backup-create-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - backup: backup
   - id: id_1
   - links: links_1
   - name: name_1


Update a backup
~~~~~~~~~~~~~~~

.. rest_method::  PUT /v3/{project_id}/backups/{backup_id}

Update a Block Storage backup. This API is available since v3.9.

Normal response codes: 202

Error response codes: Bad Request(400)

Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - backup_id: backup_id
   - backup: backup
   - description: description
   - name: name_optional
   - metadata: metadata_9

Request Example
---------------

.. literalinclude:: ./samples/backup-update-request.json
   :language: javascript

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - backup: backup
   - id: id_1
   - links: links_1
   - name: name_1

Response Example
----------------

.. literalinclude:: ./samples/backup-update-response.json
   :language: javascript


List backups for project
~~~~~~~~~~~~~~~~~~~~~~~~

.. rest_method::  GET /v3/{project_id}/backups

Lists Block Storage backups to which the project has access,
since v3.31 if non-admin users specify invalid filters in the
url, API will return bad request.

Normal response codes: 200

Error response codes: badRequest(400)

Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - all_tenants: all-tenants
   - sort: sort
   - limit: limit
   - marker: marker
   - with_count: with_count

Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - backups: backups
   - id: id_1
   - links: links_1
   - name: name_1
   - count: count

Response Example
----------------

.. literalinclude:: ./samples/backups-list-response.json
   :language: javascript


Export a backup
~~~~~~~~~~~~~~~

.. rest_method::  GET /v3/{project_id}/backups/{backup_id}/export_record

Export information about a backup.


Normal response codes: 200

Error response codes: badRequest(400), itemNotFound(404)


Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - backup_id: backup_id


Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - backup_service: backup_service
   - backup_url: backup_url

Response Example
----------------

.. literalinclude:: ./samples/backup-record-export-response.json
   :language: javascript


Import a backup
~~~~~~~~~~~~~~~

.. rest_method::  POST /v3/{project_id}/backups/{backup_id}/import_record

Import information about a backup.


Normal response codes: 201

Error response codes: badRequest(400), serviceUnavailable(503)


Request
-------

.. rest_parameters:: parameters.yaml

   - project_id: project_id_path
   - backup_id: backup_id


Request Example
---------------

.. literalinclude:: ./samples/backup-record-import-request.json
   :language: javascript


Response Parameters
-------------------

.. rest_parameters:: parameters.yaml

   - id: id_1
   - links: links_1
   - name: name_1

Response Example
----------------

.. literalinclude:: ./samples/backup-record-import-response.json

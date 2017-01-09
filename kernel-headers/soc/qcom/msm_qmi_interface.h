/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _MSM_QMI_INTERFACE_H_
#define _MSM_QMI_INTERFACE_H_
#include <linux/types.h>
#include <linux/errno.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <linux/mm.h>
#include <linux/list.h>
#include <linux/socket.h>
#include <linux/gfp.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <linux/qmi_encdec.h>
#include <linux/workqueue.h>
#define QMI_COMMON_TLV_TYPE 0
enum qmi_event_type {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QMI_RECV_MSG = 1,
  QMI_SERVER_ARRIVE,
  QMI_SERVER_EXIT,
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct qmi_handle {
  struct hlist_node handle_hash;
  void * src_port;
  void * ctl_port;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned handle_type;
  uint16_t next_txn_id;
  struct workqueue_struct * handle_wq;
  struct mutex handle_lock;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  spinlock_t notify_lock;
  void(* notify) (struct qmi_handle * handle, enum qmi_event_type event, void * notify_priv);
  void * notify_priv;
  int handle_reset;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  wait_queue_head_t reset_waitq;
  struct delayed_work ctl_work;
  void * dest_info;
  uint32_t dest_service_id;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct list_head txn_list;
  void(* ind_cb) (struct qmi_handle * handle, unsigned int msg_id, void * msg, unsigned int msg_len, void * ind_cb_priv);
  void * ind_cb_priv;
  struct delayed_work resume_tx_work;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct list_head pending_txn_list;
  struct list_head conn_list;
  struct qmi_svc_ops_options * svc_ops_options;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
enum qmi_result_type_v01 {
  QMI_RESULT_TYPE_MIN_ENUM_VAL_V01 = INT_MIN,
  QMI_RESULT_SUCCESS_V01 = 0,
  QMI_RESULT_FAILURE_V01 = 1,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QMI_RESULT_TYPE_MAX_ENUM_VAL_V01 = INT_MAX,
};
enum qmi_error_type_v01 {
  QMI_ERR_TYPE_MIN_ENUM_VAL_V01 = INT_MIN,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QMI_ERR_NONE_V01 = 0x0000,
  QMI_ERR_MALFORMED_MSG_V01 = 0x0001,
  QMI_ERR_NO_MEMORY_V01 = 0x0002,
  QMI_ERR_INTERNAL_V01 = 0x0003,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QMI_ERR_CLIENT_IDS_EXHAUSTED_V01 = 0x0005,
  QMI_ERR_INVALID_ID_V01 = 0x0029,
  QMI_ERR_ENCODING_V01 = 0x003A,
  QMI_ERR_INCOMPATIBLE_STATE_V01 = 0x005A,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  QMI_ERR_NOT_SUPPORTED_V01 = 0x005E,
  QMI_ERR_TYPE_MAX_ENUM_VAL_V01 = INT_MAX,
};
struct qmi_response_type_v01 {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  enum qmi_result_type_v01 result;
  enum qmi_error_type_v01 error;
};
struct qmi_svc_ops_options {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  unsigned version;
  uint32_t service_id;
  uint32_t service_vers;
  uint32_t service_ins;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int(* connect_cb) (struct qmi_handle * handle, void * conn_handle);
  int(* disconnect_cb) (struct qmi_handle * handle, void * conn_handle);
  int(* req_desc_cb) (unsigned int msg_id, struct msg_desc * * req_desc);
  int(* req_cb) (struct qmi_handle * handle, void * conn_handle, void * req_handle, unsigned int msg_id, void * req);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
#define get_qmi_response_type_v01_ei() NULL
#endif

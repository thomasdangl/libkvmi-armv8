#ifndef __LIBKVMI_COMPAT_V7_H__
#define __LIBKVMI_COMPAT_V7_H__

#define KVMI_MSG_SIZE (4096 * 2 - sizeof(struct kvmi_msg_hdr))
#define KVMI_NUM_EVENTS KVMI_NEXT_VCPU_EVENT

/* unsupported commands */
#define KVMI_CONTROL_CMD_RESPONSE  -1
#define KVMI_CONTROL_EPT_VIEW      -1
#define KVMI_DISABLE_VE            -1
#define KVMI_GET_EPT_PAGE_CONV     -1
#define KVMI_GET_EPT_VIEW          -1
#define KVMI_GET_MAP_TOKEN         -1
#define KVMI_GET_MAX_GFN           -1
#define KVMI_SET_EPT_PAGE_CONV     -1
#define KVMI_SET_PAGE_WRITE_BITMAP -1
#define KVMI_SET_VE_INFO_PAGE      -1
#define KVMI_SWITCH_EPT_VIEW       -1
#define KVMI_VCPU_CHANGE_GFN       -1

/* unsupported events */
#define KVMI_EVENT_CREATE_VCPU KVMI_NEXT_VCPU_MESSAGE
#define KVMI_EVENT_CPUID       KVMI_NEXT_VCPU_MESSAGE + 1

/* renamed command IDs */
#define KVMI_CHECK_COMMAND     KVMI_VM_CHECK_COMMAND
#define KVMI_CHECK_EVENT       KVMI_VM_CHECK_EVENT
#define KVMI_CONTROL_VM_EVENTS KVMI_VM_CONTROL_EVENTS
#define KVMI_PAUSE_VCPU        KVMI_VM_PAUSE_VCPU
#define KVMI_READ_PHYSICAL     KVMI_VM_READ_PHYSICAL
#define KVMI_SET_PAGE_ACCESS   KVMI_VM_SET_PAGE_ACCESS
#define KVMI_WRITE_PHYSICAL    KVMI_VM_WRITE_PHYSICAL
#define KVMI_CONTROL_CR       KVMI_VCPU_CONTROL_CR
#define KVMI_CONTROL_EVENTS   KVMI_VCPU_CONTROL_EVENTS
#define KVMI_CONTROL_MSR      KVMI_VCPU_CONTROL_MSR
#define KVMI_GET_CPUID        KVMI_VCPU_GET_CPUID
#define KVMI_GET_MTRR_TYPE    KVMI_VCPU_GET_MTRR_TYPE
#define KVMI_GET_REGISTERS    KVMI_VCPU_GET_REGISTERS
#define KVMI_GET_XSAVE        KVMI_VCPU_GET_XSAVE
#define KVMI_INJECT_EXCEPTION KVMI_VCPU_INJECT_EXCEPTION
#define KVMI_SET_REGISTERS    KVMI_VCPU_SET_REGISTERS

/* renamed event IDs */
#define KVMI_EVENT_UNHOOK      KVMI_VM_EVENT_UNHOOK
#define KVMI_EVENT_BREAKPOINT  KVMI_VCPU_EVENT_BREAKPOINT
#define KVMI_EVENT_CR          KVMI_VCPU_EVENT_CR
#define KVMI_EVENT_DESCRIPTOR  KVMI_VCPU_EVENT_DESCRIPTOR
#define KVMI_EVENT_HYPERCALL   KVMI_VCPU_EVENT_HYPERCALL
#define KVMI_EVENT_MSR         KVMI_VCPU_EVENT_MSR
#define KVMI_EVENT_PAUSE_VCPU  KVMI_VCPU_EVENT_PAUSE
#define KVMI_EVENT_PF          KVMI_VCPU_EVENT_PF
#define KVMI_EVENT_SINGLESTEP  KVMI_VCPU_EVENT_SINGLESTEP
#define KVMI_EVENT_TRAP        KVMI_VCPU_EVENT_TRAP
#define KVMI_EVENT_XSETBV      KVMI_VCPU_EVENT_XSETBV

/* renamed command structures */
#define kvmi_get_cpuid_reply     kvmi_vcpu_get_cpuid_reply
#define kvmi_get_mtrr_type_reply kvmi_vcpu_get_mtrr_type_reply
#define kvmi_get_registers_reply kvmi_vcpu_get_registers_reply

struct kvmi_set_page_access {
	__u16 count;
	__u16 padding1;
	__u32 padding2;
	struct kvmi_page_access_entry entries[0];
};

struct kvmi_pause_vcpu {
	__u16 vcpu;
	__u8 wait;
	__u8 padding1;
	__u32 padding2;
};

struct kvmi_read_physical {
	__u64 gpa;
	__u16 size;
	__u16 padding1;
	__u32 padding2;
};

struct kvmi_write_physical {
	__u64 gpa;
	__u16 size;
	__u16 padding1;
	__u32 padding2;
	__u8  data[0];
};

struct kvmi_check_command {
	__u16 id;
	__u16 padding1;
	__u32 padding2;
};

struct kvmi_check_event {
	__u16 id;
	__u16 padding1;
	__u32 padding2;
};

struct kvmi_control_cr {
	__u8 cr;
	__u8 enable;
	__u16 padding1;
	__u32 padding2;
};

struct kvmi_control_events {
	__u16 event_id;
	__u8 enable;
	__u8 padding1;
	__u32 padding2;
};

struct kvmi_control_msr {
	__u8 enable;
	__u8 padding1;
	__u16 padding2;
	__u32 msr;
};

struct kvmi_control_vm_events {
	__u16 event_id;
	__u8 enable;
	__u8 padding1;
	__u32 padding2;
};

struct kvmi_get_cpuid {
	__u32 function;
	__u32 index;
};

struct kvmi_get_mtrr_type {
	__u64 gpa;
};

struct kvmi_get_registers {
	__u16 nmsrs;
	__u16 padding1;
	__u32 padding2;
	__u32 msrs_idx[0];
};

struct kvmi_inject_exception {
	__u8 nr;
	__u8 padding1;
	__u16 padding2;
	__u32 error_code;
	__u64 address;
};


/* renamed event structures */
#define kvmi_event_breakpoint kvmi_vcpu_event_breakpoint
#define kvmi_event_cr         kvmi_vcpu_event_cr
#define kvmi_event_cr_reply   kvmi_vcpu_event_cr_reply
#define kvmi_event_descriptor kvmi_vcpu_event_descriptor
#define kvmi_event_msr        kvmi_vcpu_event_msr
#define kvmi_event_msr_reply  kvmi_vcpu_event_msr_reply
#define kvmi_event_pf         kvmi_vcpu_event_pf
#define kvmi_event_reply      kvmi_vcpu_event_reply
#define kvmi_event_trap       kvmi_vcpu_event_trap

struct kvmi_event {
	struct kvmi_event_hdr  hdr;
	struct kvmi_vcpu_event ev;
};

struct kvmi_event_cpuid {
	__u32 function;
	__u32 index;
	__u8  insn_length;
	__u8  padding1[3];
	__u32 padding2;
};

#define KVM_GUEST_MEM_OPEN	_IOW('i', 0x01, unsigned char *)
#define KVM_GUEST_MEM_MAP	_IOWR('i', 0x02, struct kvmi_guest_mem_map)
#define KVM_GUEST_MEM_UNMAP	_IOW('i', 0x03, unsigned long)

struct kvmi_mem_token {
	__u64 token[4];
};

struct kvmi_guest_mem_map {
	struct kvmi_mem_token token;		/* In */
	__u64 gpa;				/* In/Out */
	__u64 length;				/* Out */
};

struct kvmi_control_cmd_response {
	__u8 enable;
	__u8 now;
	__u16 padding1;
	__u32 padding2;
};

struct kvmi_page_write_bitmap_entry {
	__u64 gpa;
	__u32 bitmap;
	__u32 padding;
};

struct kvmi_set_page_write_bitmap {
	__u16 view;
	__u16 count;
	__u32 padding;
	struct kvmi_page_write_bitmap_entry entries[0];
};

struct kvmi_get_max_gfn_reply {
	__u64 gfn;
};
struct kvmi_set_ve_info_page {
	__u64 gpa;
	__u8  trigger_vmexit;
	__u8  padding[7];
};

struct kvmi_set_ept_page_conv_req {
	__u16 view;
	__u8  sve;
	__u8  padding[5];
	__u64 gpa;
};

struct kvmi_switch_ept_view_req {
	__u16 view;
	__u16 padding[3];
};

struct kvmi_get_ept_view_reply {
	__u16 view;
	__u8  padding[6];
};

struct kvmi_get_ept_page_conv_req {
	__u16 view;
	__u16 padding[3];
 	__u64 gpa;
};

struct kvmi_get_ept_page_conv_reply {
	__u8 sve;
	__u8 access;
 	__u8 padding[7];
};

struct kvmi_control_ept_view_req {
	__u16 view;
	__u8  visible;
	__u8  padding1;
 	__u32 padding2;
};

struct kvmi_vcpu_change_gfn {
	__u64 old_gfn;
	__u64 new_gfn;
};

struct kvmi_event_pf_reply {
};

#endif

/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_ASM_ARM64_KVMI_H
#define _UAPI_ASM_ARM64_KVMI_H

/*
 * KVM introspection - ARM64 specific structures and definitions
 */

#include <asm/kvm.h>

enum {
	KVM_HC_XEN_HVM_OP_GUEST_REQUEST_VM_EVENT = 24,
};

struct kvmi_vcpu_get_info_reply {
	__u64 tsc_speed;
};

struct kvmi_vcpu_event_arch {
	struct kvm_regs regs;
	struct kvm_sregs sregs;
};

struct kvmi_vcpu_get_registers_reply {
	struct kvm_regs regs;
	struct kvm_sregs sregs;
};

struct kvmi_vcpu_get_cpuid {
	__u32 function;
	__u32 index;
};

struct kvmi_vcpu_get_cpuid_reply {
	__u32 eax;
	__u32 ebx;
	__u32 ecx;
	__u32 edx;
};

struct kvmi_vcpu_control_cr {
	__u8 cr;
	__u8 enable;
	__u16 padding1;
	__u32 padding2;
};

struct kvmi_vcpu_event_cr {
	__u8 cr;
	__u8 padding[7];
	__u64 old_value;
	__u64 new_value;
};

struct kvmi_vcpu_event_cr_reply {
	__u64 new_val;
};

struct kvmi_vcpu_event_trap {
	__u8 nr;
	__u8 padding1;
	__u16 padding2;
	__u32 error_code;
	__u64 address;
};

struct kvmi_vcpu_inject_exception {
	__u8 nr;
	__u8 padding1;
	__u16 padding2;
	__u32 error_code;
	__u64 address;
};

struct kvmi_vcpu_event_xsetbv {
	__u8 xcr;
	__u8 padding[7];
	__u64 old_value;
	__u64 new_value;
};

struct kvmi_vcpu_get_xcr {
	__u8 xcr;
	__u8 padding[7];
};

struct kvmi_vcpu_get_xcr_reply {
	__u64 value;
};

// TODO: what about these on ARM?
struct kvmi_vcpu_get_xsave_reply {
	//struct kvm_xsave xsave;
};

struct kvmi_vcpu_set_xsave {
	//struct kvm_xsave xsave;
};

struct kvmi_vcpu_get_mtrr_type {
	__u64 gpa;
};

struct kvmi_vcpu_get_mtrr_type_reply {
	__u8 type;
	__u8 padding[7];
};

enum {
	KVMI_DESC_IDTR = 1,
	KVMI_DESC_GDTR = 2,
	KVMI_DESC_LDTR = 3,
	KVMI_DESC_TR   = 4,
};

struct kvmi_vcpu_event_descriptor {
	__u8 descriptor;
	__u8 write;
	__u8 padding[6];
};

struct kvmi_vcpu_control_msr {
	__u8 enable;
	__u8 padding1;
	__u16 padding2;
	__u32 msr;
};

struct kvmi_vcpu_event_msr {
	__u32 msr;
	__u32 padding;
	__u64 old_value;
	__u64 new_value;
};

struct kvmi_vcpu_event_msr_reply {
	__u64 new_val;
};

struct kvmi_features {
	__u8 singlestep;
	__u8 padding[7];
};

#endif /* _UAPI_ASM_ARM64_KVMI_H */

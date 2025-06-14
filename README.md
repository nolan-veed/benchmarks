# benchmarks

Uses Google Benchmarks to explore things!


### Setup

I mostly work on my `Dell XPS 15 9510` laptop, which has the latest Ubuntu LTS, on 16 logical cores and 32Gig memory.

Here's a snippet from `/proc/cpuinfo`

    processor	: 0
    vendor_id	: GenuineIntel
    cpu family	: 6
    model		: 141
    model name	: 11th Gen Intel(R) Core(TM) i9-11900H @ 2.50GHz
    stepping	: 1
    microcode	: 0x56
    cpu MHz		: 2621.333
    cache size	: 24576 KB
    physical id	: 0
    siblings	: 16
    core id		: 0
    cpu cores	: 8
    apicid		: 0
    initial apicid	: 0
    fpu		: yes
    fpu_exception	: yes
    cpuid level	: 27
    wp		: yes
    flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx pdpe1gb rdtscp lm constant_tsc art arch_perfmon pebs bts rep_good nopl xtopology nonstop_tsc cpuid aperfmperf tsc_known_freq pni pclmulqdq dtes64 monitor ds_cpl vmx est tm2 ssse3 sdbg fma cx16 xtpr pdcm pcid sse4_1 sse4_2 x2apic movbe popcnt tsc_deadline_timer aes xsave avx f16c rdrand lahf_lm abm 3dnowprefetch cpuid_fault epb cat_l2 cdp_l2 ssbd ibrs ibpb stibp ibrs_enhanced tpr_shadow flexpriority ept vpid ept_ad fsgsbase tsc_adjust bmi1 avx2 smep bmi2 erms invpcid rdt_a avx512f avx512dq rdseed adx smap avx512ifma clflushopt clwb intel_pt avx512cd sha_ni avx512bw avx512vl xsaveopt xsavec xgetbv1 xsaves split_lock_detect user_shstk dtherm ida arat pln pts hwp hwp_notify hwp_act_window hwp_epp hwp_pkg_req vnmi avx512vbmi umip pku ospke avx512_vbmi2 gfni vaes vpclmulqdq avx512_vnni avx512_bitalg avx512_vpopcntdq rdpid movdiri movdir64b fsrm avx512_vp2intersect md_clear ibt flush_l1d arch_capabilities
    vmx flags	: vnmi preemption_timer posted_intr invvpid ept_x_only ept_ad ept_1gb flexpriority apicv tsc_offset vtpr mtf vapic ept vpid unrestricted_guest vapic_reg vid ple pml ept_violation_ve ept_mode_based_exec tsc_scaling
    bugs		: spectre_v1 spectre_v2 spec_store_bypass swapgs eibrs_pbrsb gds bhi
    bogomips	: 4992.00
    clflush size	: 64
    cache_alignment	: 64
    address sizes	: 39 bits physical, 48 bits virtual
    power management:

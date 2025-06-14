/* include/net-snmp/net-snmp-config.h.  Generated from net-snmp-config.h.in by configure.  */
/* include/net-snmp/net-snmp-config.h.in.  Generated from configure.ac by autoheader.  */

/*
 * net-snmp configuration header file
 *
 * NOTE: DO NOT EDIT include/net-snmp/net-snmp-config.h.in as your changes
 *       will be overwritten. This content is in acconfig.h and merged
 *       into include/net-snmp/net-snmp-config.h.in by autoheader.
 */
/* Portions of this file are subject to the following copyright(s).  See
 * the Net-SNMP's COPYING file for more details and other copyrights
 * that may apply:
 */
/*
 * Portions of this file are copyrighted by:
 * Copyright � 2003 Sun Microsystems, Inc. All rights reserved.
 * Use is subject to license terms specified in the COPYING file
 * distributed with the Net-SNMP package.
 *
 * Portions of this file are copyrighted by:
 * Copyright (c) 2016 VMware, Inc. All rights reserved.
 * Use is subject to license terms specified in the COPYING file
 * distributed with the Net-SNMP package.
 */

#ifndef NET_SNMP_CONFIG_H
#define NET_SNMP_CONFIG_H


/* ********* NETSNMP_MARK_BEGIN_AUTOCONF_DEFINITIONS ********* */
/*
 * put all autoconf-specific definitions below here
 *
 */
#ifndef NETSNMP_NO_AUTOCONF_DEFINITIONS

/* definitions added by configure on-the-fly */

#define config_error(x)

#define config_warning(x)

#define config_belongs_in(x)

#define config_exclude(x)

#define config_arch_require(x,y)

#define config_version_require(x)

#define config_require(x)

#define config_add_mib(x)

#define config_parse_dot_conf(w,x,y,z)

/* Define to 1 if using 'alloca.c'. */
/* #undef C_ALLOCA */

/* location of swap device */
/* #undef DMEM_LOC */

/* Define if you want local DNSSEC validation support */
/* #undef DNSSEC_LOCAL_VALIDATION */

/* Environment separator character surrounded by double quotes. */
#define ENV_SEPARATOR ":"

/* Environment separator character surrounded by single quotes. */
#define ENV_SEPARATOR_CHAR ':'

/* location of mount table list */
#define ETC_MNTTAB "/etc/mtab"

/* Define to 1 if you have the `AES_cfb128_encrypt' function. */
#define HAVE_AES_CFB128_ENCRYPT 1

/* Define to 1 if you have 'alloca', as a function or macro. */
#define HAVE_ALLOCA 1

/* Define to 1 if <alloca.h> works. */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the <arpa/inet.h> header file. */
#define HAVE_ARPA_INET_H 1

/* Define to 1 if you have the <asm/page.h> header file. */
/* #undef HAVE_ASM_PAGE_H */

/* Define to 1 if you have the <asm/types.h> header file. */
#define HAVE_ASM_TYPES_H 1

/* Define to 1 if you have the `ASN1_STRING_get0_data' function. */
#define HAVE_ASN1_STRING_GET0_DATA 1

/* Define to 1 if you have the `asprintf' function. */
#define HAVE_ASPRINTF 1

/* Define to 1 if you have the `cgetnext' function. */
/* #undef HAVE_CGETNEXT */

/* Define to 1 if you have the `chown' function. */
#define HAVE_CHOWN 1

/* Define to 1 if you have the `clock_gettime' library */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the `closedir' function. */
#define HAVE_CLOSEDIR 1

/* Define to 1 if you have the `closesocket' function. */
/* #undef HAVE_CLOSESOCKET */

/* Define to 1 if you have the <com_err.h> header file. */
/* #undef HAVE_COM_ERR_H */

/* Define to 1 if the system has the type `Counter64'. */
/* #undef HAVE_COUNTER64 */

/* Define to 1 if you have the <crt_externs.h> header file. */
/* #undef HAVE_CRT_EXTERNS_H */

/* Define to 1 if you have the <curses.h> header file. */
/* #undef HAVE_CURSES_H */

/* Define to 1 if you have the declaration of `daylight', and to 0 if you
   don't. */
#define HAVE_DECL_DAYLIGHT 1

/* Define to 1 if you have the declaration of `sensors_get_all_subfeatures',
   and to 0 if you don't. */
#define HAVE_DECL_SENSORS_GET_ALL_SUBFEATURES 1

/* Define to 1 if you have the declaration of `timezone', and to 0 if you
   don't. */
#define HAVE_DECL_TIMEZONE 1

/* define to 1 if you have IRE_CACHE defined in <inet/ip.h> header file. */
/* #undef HAVE_DEFINED_IRE_CACHE */

/* define if you have devstat_getdevs() */
/* #undef HAVE_DEVSTAT_GETDEVS */

/* Define to 1 if you have the `DH_get0_key' function. */
#define HAVE_DH_GET0_KEY 1

/* Define to 1 if you have the `DH_get0_pqg' function. */
#define HAVE_DH_GET0_PQG 1

/* Define to 1 if you have the `DH_set0_pqg' function. */
#define HAVE_DH_SET0_PQG 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `dlopen' function. */
#define HAVE_DLOPEN 1

/* Set if the dpkg-query command is available */
#define HAVE_DPKG_QUERY 1

/* Define to 1 if you have the `DTLSv1_method' function. */
#define HAVE_DTLSV1_METHOD 1

/* Define to 1 if you have the `DTLS_method' function. */
#define HAVE_DTLS_METHOD 1

/* Define to 1 if you have the `endfsent' function. */
#define HAVE_ENDFSENT 1

/* Define to 1 if you have the `ERR_get_error_all' function. */
#define HAVE_ERR_GET_ERROR_ALL 1

/* Define to 1 if you have the <err.h> header file. */
#define HAVE_ERR_H 1

/* Define to 1 if you have the <et/com_err.h> header file. */
/* #undef HAVE_ET_COM_ERR_H */

/* Define to 1 if you have the `eval_pv' function. */
/* #undef HAVE_EVAL_PV */

/* Define to 1 if you have the `EVP_MD_CTX_create' function. */
/* #undef HAVE_EVP_MD_CTX_CREATE */

/* Define to 1 if you have the `EVP_MD_CTX_destroy' function. */
/* #undef HAVE_EVP_MD_CTX_DESTROY */

/* Define to 1 if you have the `EVP_MD_CTX_free' function. */
#define HAVE_EVP_MD_CTX_FREE 1

/* Define to 1 if you have the `EVP_MD_CTX_new' function. */
#define HAVE_EVP_MD_CTX_NEW 1

/* Define to 1 if you have the `EVP_sha224' function. */
#define HAVE_EVP_SHA224 1

/* Define to 1 if you have the `EVP_sha384' function. */
#define HAVE_EVP_SHA384 1

/* Define to 1 if you have the `execv' function. */
#define HAVE_EXECV 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fgetc_unlocked' function. */
#define HAVE_FGETC_UNLOCKED 1

/* Define to 1 if you have the `flockfile' function. */
#define HAVE_FLOCKFILE 1

/* Define to 1 if you have the `fork' function. */
#define HAVE_FORK 1

/* Define to 1 if you have the `forkall' function. */
/* #undef HAVE_FORKALL */

/* Define to 1 if you have the <fstab.h> header file. */
#define HAVE_FSTAB_H 1

/* Define to 1 if you have the `fsync' function. */
#define HAVE_FSYNC 1

/* Define to 1 if you have the `funlockfile' function. */
#define HAVE_FUNLOCKFILE 1

/* Define to 1 if you have the `gai_strerror' function. */
#define HAVE_GAI_STRERROR 1

/* Define to 1 if you have the `getaddrinfo' function. */
#define HAVE_GETADDRINFO 1

/* define if you have getdevs() */
/* #undef HAVE_GETDEVS */

/* Define to 1 if you have the `getdtablesize' function. */
#define HAVE_GETDTABLESIZE 1

/* Define to 1 if you have the `getfsent' function. */
#define HAVE_GETFSENT 1

/* Define to 1 if you have the `getfsstat' function. */
/* #undef HAVE_GETFSSTAT */

/* Define to 1 if you have the `getgrnam' function. */
#define HAVE_GETGRNAM 1

/* Define to 1 if you have the `gethostbyaddr' function. */
#define HAVE_GETHOSTBYADDR 1

/* Define to 1 if you have the `gethostbyname' function. */
#define HAVE_GETHOSTBYNAME 1

/* Define to 1 if you have the `gethostbyname2' function. */
#define HAVE_GETHOSTBYNAME2 1

/* Define to 1 if you have the `gethostname' function. */
#define HAVE_GETHOSTNAME 1

/* Define to 1 if you have the `getipnodebyname' function. */
/* #undef HAVE_GETIPNODEBYNAME */

/* Define to 1 if you have the `getloadavg' function. */
#define HAVE_GETLOADAVG 1

/* Define to 1 if you have the `getlogin' function. */
#define HAVE_GETLOGIN 1

/* Define to 1 if you have the `getmntent' function. */
#define HAVE_GETMNTENT 1

/* Define to 1 if you have the `getmntinfo' function. */
/* #undef HAVE_GETMNTINFO */

/* Define to 1 if you have the `getopt' function. */
#define HAVE_GETOPT 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the `getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define to 1 if you have the `getpid' function. */
#define HAVE_GETPID 1

/* Define to 1 if you have the `getpwnam' function. */
#define HAVE_GETPWNAM 1

/* Define to 1 if you have the `gettimeofday' function. */
#define HAVE_GETTIMEOFDAY 1

/* Define to 1 if you have the `getvfsstat' function. */
/* #undef HAVE_GETVFSSTAT */

/* Define to 1 if you have the <grp.h> header file. */
#define HAVE_GRP_H 1

/* Define to 1 if you have the `hasmntopt' function. */
#define HAVE_HASMNTOPT 1

/* Define to 1 if you have the headerGet function. */
/* #undef HAVE_HEADERGET */

/* Define to 1 if you have the `if_freenameindex' function. */
#define HAVE_IF_FREENAMEINDEX 1

/* Define to 1 if you have the `if_indextoname' function. */
#define HAVE_IF_INDEXTONAME 1

/* Define to 1 if you have the `if_nameindex' function. */
#define HAVE_IF_NAMEINDEX 1

/* Define to 1 if you have the `if_nametoindex' function. */
#define HAVE_IF_NAMETOINDEX 1

/* Define to 1 if you have the <inet/common.h> header file. */
/* #undef HAVE_INET_COMMON_H */

/* Define to 1 if you have the <inet/ip.h> header file. */
/* #undef HAVE_INET_IP_H */

/* Define to 1 if you have the <inet/mib2.h> header file. */
/* #undef HAVE_INET_MIB2_H */

/* Define to 1 if you have the `inet_ntop' function. */
#define HAVE_INET_NTOP 1

/* Define to 1 if you have the `inet_pton' function. */
#define HAVE_INET_PTON 1

/* Define to 1 if you have the `initgroups' function. */
#define HAVE_INITGROUPS 1

/* Define to 1 if the system has the type `intmax_t'. */
#define HAVE_INTMAX_T 1

/* Define to 1 if the system has the type `intptr_t'. */
#define HAVE_INTPTR_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if the system has the type `in_addr_t'. */
#define HAVE_IN_ADDR_T 1

/* Define to 1 if you have the <ioctls.h> header file. */
/* #undef HAVE_IOCTLS_H */

/* Define to 1 if you have the <io.h> header file. */
/* #undef HAVE_IO_H */

/* Define to 1 if you have the <iphlpapi.h> header file. */
/* #undef HAVE_IPHLPAPI_H */

/* Set if IP_PKTINFO is usable */
#define HAVE_IP_PKTINFO 1

/* Set if IP_RECVDSTADDR is usable */
/* #undef HAVE_IP_RECVDSTADDR */

/* Define to 1 if you have the `kinfo_get_cpus' function. */
/* #undef HAVE_KINFO_GET_CPUS */

/* Define to 1 if you have the `knlist' function. */
/* #undef HAVE_KNLIST */

/* Define to 1 if you have the `krb5_auth_con_getrecvsubkey' function. */
/* #undef HAVE_KRB5_AUTH_CON_GETRECVSUBKEY */

/* Define to 1 if you have the `krb5_auth_con_getsendsubkey' function. */
/* #undef HAVE_KRB5_AUTH_CON_GETSENDSUBKEY */

/* Define to 1 if `enctype' is a member of `krb5_keyblock'. */
/* #undef HAVE_KRB5_KEYBLOCK_ENCTYPE */

/* Define to 1 if you have the <kstat.h> header file. */
/* #undef HAVE_KSTAT_H */

/* Define to 1 if you have the `kvm_getfile2' function. */
/* #undef HAVE_KVM_GETFILE2 */

/* Define to 1 if you have the `kvm_getfiles' function. */
/* #undef HAVE_KVM_GETFILES */

/* Define to 1 if you have the `kvm_getproc2' function. */
/* #undef HAVE_KVM_GETPROC2 */

/* Define to 1 if you have the `kvm_getprocs' function. */
/* #undef HAVE_KVM_GETPROCS */

/* Define to 1 if you have the `kvm_getswapinfo' function. */
/* #undef HAVE_KVM_GETSWAPINFO */

/* Define to 1 if you have the <kvm.h> header file. */
/* #undef HAVE_KVM_H */

/* Define to 1 if you have the `kvm_openfiles' function. */
/* #undef HAVE_KVM_OPENFILES */

/* Define to 1 if you have the OpenSSL library (-lcrypto or -leay32). */
#define HAVE_LIBCRYPTO 1

/* Define to 1 if you have the `elf' library (-lelf). */
/* #undef HAVE_LIBELF */

/* Define to 1 if you have the `mld' library (-lmld). */
/* #undef HAVE_LIBMLD */

/* Define to 1 if <netlink/netlink.h> provides the libnl3 API */
/* #undef HAVE_LIBNL3 */

/* define if you have libnm */
/* #undef HAVE_LIBNM */

/* Define to 1 if you have the `nsl' library (-lnsl). */
/* #undef HAVE_LIBNSL */

/* Define to 1 if you have the <libperfstat.h> header file. */
/* #undef HAVE_LIBPERFSTAT_H */

/* Define to 1 if you have the `pkcs11' library (-lpkcs11). */
/* #undef HAVE_LIBPKCS11 */

/* define if you have BSD pkg-ng */
/* #undef HAVE_LIBPKG */

/* Define to 1 if you have the `pthread' library (-lpthread). */
/* #undef HAVE_LIBPTHREAD */

/* Define to 1 if you have the `rpm' library (-lrpm). */
/* #undef HAVE_LIBRPM */

/* Define to 1 if you have the `RSAglue' library (-lRSAglue). */
/* #undef HAVE_LIBRSAGLUE */

/* Define to 1 if you have the `rsaref' library (-lrsaref). */
/* #undef HAVE_LIBRSAREF */

/* Define to 1 if you have the `sres' library (-lsres). */
/* #undef HAVE_LIBSRES */

/* Define to 1 if you have the `ssh2' library (-lssh2). */
/* #undef HAVE_LIBSSH2 */

/* Define to 1 if you have the `ssl' library (-lssl). */
#define HAVE_LIBSSL 1

/* Define to 1 if your `ssl' library supports DTLS (-lssl). */
#define HAVE_LIBSSL_DTLS 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define to 1 if you have the <linux/ethtool.h> header file. */
#define HAVE_LINUX_ETHTOOL_H 1

/* Define if __u8 .. __u64 must be declared explicitly before including
   <linux/ethtool.h> */
/* #undef HAVE_LINUX_ETHTOOL_NEEDS_U64 */

/* Define to 1 if you have the <linux/hdreg.h> header file. */
#define HAVE_LINUX_HDREG_H 1

/* Define to 1 if you have the <linux/netlink.h> header file. */
#define HAVE_LINUX_NETLINK_H 1

/* Define to 1 if you have the <linux/rtnetlink.h> header file. */
#define HAVE_LINUX_RTNETLINK_H 1

/* Define to 1 if you have the <linux/tasks.h> header file. */
/* #undef HAVE_LINUX_TASKS_H */

/* Define to 1 if you have the <lm.h> header file. */
/* #undef HAVE_LM_H */

/* Define to 1 if you have the `load_defaults' function. */
/* #undef HAVE_LOAD_DEFAULTS */

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the `localtime_r' function. */
#define HAVE_LOCALTIME_R 1

/* Define to 1 if the system has the type `long long int'. */
#define HAVE_LONG_LONG_INT 1

/* Set if the lpstat command is available */
/* #undef HAVE_LPSTAT */

/* Define to 1 if you have the `lrand48' function. */
#define HAVE_LRAND48 1

/* Define to 1 if you have the `lseek64' function. */
#define HAVE_LSEEK64 1

/* Define to 1 if you have the <machine/param.h> header file. */
/* #undef HAVE_MACHINE_PARAM_H */

/* Define to 1 if you have the <machine/pte.h> header file. */
/* #undef HAVE_MACHINE_PTE_H */

/* Define to 1 if you have the <machine/types.h> header file. */
/* #undef HAVE_MACHINE_TYPES_H */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if the system has the type `mib2_ipIfStatsEntry_t'. */
/* #undef HAVE_MIB2_IPIFSTATSENTRY_T */

/* Define if MIB_IF_TABLE2 is available */
/* #undef HAVE_MIB_IF_TABLE2 */

/* Define to 1 if you have the <minix/config.h> header file. */
/* #undef HAVE_MINIX_CONFIG_H */

/* Define to 1 if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have the `mktime' function. */
#define HAVE_MKTIME 1

/* Define to 1 if you have the <mntent.h> header file. */
#define HAVE_MNTENT_H 1

/* Define to 1 if you have the <mtab.h> header file. */
/* #undef HAVE_MTAB_H */

/* Define to 1 if you have the `mysql_init' function. */
#define HAVE_MYSQL_INIT 1

/* Define to 1 if you have the `mysql_options' function. */
#define HAVE_MYSQL_OPTIONS 1

/* Define to 1 if you have the <my_global.h> header file. */
/* #undef HAVE_MY_GLOBAL_H */

/* Define if MY_INIT() is availabe in libmysqlclient */
/* #undef HAVE_MY_INIT */

/* Define if having my_load_defaults() */
#define HAVE_MY_LOAD_DEFAULTS 1

/* Define to 1 if you have the <my_sys.h> header file. */
/* #undef HAVE_MY_SYS_H */

/* Define to 1 if you have the <nbutil.h> header file. */
/* #undef HAVE_NBUTIL_H */

/* Define to 1 if you have the <ncurses/curses.h> header file. */
/* #undef HAVE_NCURSES_CURSES_H */

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <netdb.h> header file. */
#define HAVE_NETDB_H 1

/* Define to 1 if you have the <netinet6/in6_pcb.h> header file. */
/* #undef HAVE_NETINET6_IN6_PCB_H */

/* Define to 1 if you have the <netinet6/in6_var.h> header file. */
/* #undef HAVE_NETINET6_IN6_VAR_H */

/* Define to 1 if you have the <netinet6/ip6_var.h> header file. */
/* #undef HAVE_NETINET6_IP6_VAR_H */

/* Define to 1 if you have the <netinet6/nd6.h> header file. */
/* #undef HAVE_NETINET6_ND6_H */

/* Define to 1 if you have the <netinet6/tcp6_fsm.h> header file. */
/* #undef HAVE_NETINET6_TCP6_FSM_H */

/* Define to 1 if you have the <netinet6/tcp6.h> header file. */
/* #undef HAVE_NETINET6_TCP6_H */

/* Define to 1 if you have the <netinet6/tcp6_timer.h> header file. */
/* #undef HAVE_NETINET6_TCP6_TIMER_H */

/* Define to 1 if you have the <netinet6/tcp6_var.h> header file. */
/* #undef HAVE_NETINET6_TCP6_VAR_H */

/* Define to 1 if you have the <netinet/icmp6.h> header file. */
#define HAVE_NETINET_ICMP6_H 1

/* Define to 1 if you have the <netinet/icmp_var.h> header file. */
/* #undef HAVE_NETINET_ICMP_VAR_H */

/* Define to 1 if you have the <netinet/if_ether.h> header file. */
#define HAVE_NETINET_IF_ETHER_H 1

/* Define to 1 if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define to 1 if you have the <netinet/in_pcb.h> header file. */
/* #undef HAVE_NETINET_IN_PCB_H */

/* Define to 1 if you have the <netinet/in_systm.h> header file. */
#define HAVE_NETINET_IN_SYSTM_H 1

/* Define to 1 if you have the <netinet/in_var.h> header file. */
/* #undef HAVE_NETINET_IN_VAR_H */

/* Define to 1 if you have the <netinet/ip6.h> header file. */
#define HAVE_NETINET_IP6_H 1

/* Define to 1 if you have the <netinet/ip.h> header file. */
#define HAVE_NETINET_IP_H 1

/* Define to 1 if you have the <netinet/ip_icmp.h> header file. */
#define HAVE_NETINET_IP_ICMP_H 1

/* Define to 1 if you have the <netinet/ip_var.h> header file. */
/* #undef HAVE_NETINET_IP_VAR_H */

/* Define to 1 if you have the <netinet/tcpip.h> header file. */
/* #undef HAVE_NETINET_TCPIP_H */

/* Define to 1 if you have the <netinet/tcp_fsm.h> header file. */
/* #undef HAVE_NETINET_TCP_FSM_H */

/* Define to 1 if you have the <netinet/tcp.h> header file. */
#define HAVE_NETINET_TCP_H 1

/* Define to 1 if you have the <netinet/tcp_timer.h> header file. */
/* #undef HAVE_NETINET_TCP_TIMER_H */

/* Define to 1 if you have the <netinet/tcp_var.h> header file. */
/* #undef HAVE_NETINET_TCP_VAR_H */

/* Define to 1 if you have the <netinet/udp.h> header file. */
#define HAVE_NETINET_UDP_H 1

/* Define to 1 if you have the <netinet/udp_var.h> header file. */
/* #undef HAVE_NETINET_UDP_VAR_H */

/* Define to 1 if you have the <netipx/ipx.h> header file. */
#define HAVE_NETIPX_IPX_H 1

/* Define to 1 if you have the <netlink/netlink.h> header file. */
/* #undef HAVE_NETLINK_NETLINK_H */

/* Define to 1 if you have the <net/if_arp.h> header file. */
#define HAVE_NET_IF_ARP_H 1

/* Define to 1 if you have the <net/if_dl.h> header file. */
/* #undef HAVE_NET_IF_DL_H */

/* Define to 1 if you have the <net/if.h> header file. */
#define HAVE_NET_IF_H 1

/* Define to 1 if you have the <net/if_mib.h> header file. */
/* #undef HAVE_NET_IF_MIB_H */

/* Define to 1 if you have the <net/if_types.h> header file. */
/* #undef HAVE_NET_IF_TYPES_H */

/* Define to 1 if you have the <net/if_var.h> header file. */
/* #undef HAVE_NET_IF_VAR_H */

/* Define to 1 if you have the <net/route.h> header file. */
#define HAVE_NET_ROUTE_H 1

/* Define to 1 if the system has the type `nfds_t'. */
#define HAVE_NFDS_T 1

/* Define to 1 if you have the `nlist' function. */
/* #undef HAVE_NLIST */

/* Define to 1 if you have the `nlist64' function. */
/* #undef HAVE_NLIST64 */

/* Define to 1 if you have the <nlist.h> header file. */
/* #undef HAVE_NLIST_H */

/* Define to 1 if the system has the type `off64_t'. */
#define HAVE_OFF64_T 1

/* Define to 1 if you have the `opendir' function. */
#define HAVE_OPENDIR 1

/* Define to 1 if you have the <openssl/aes.h> header file. */
#define HAVE_OPENSSL_AES_H 1

/* Define to 1 if you have the <openssl/des.h> header file. */
#define HAVE_OPENSSL_DES_H 1

/* Define to 1 if you have the <openssl/dh.h> header file. */
#define HAVE_OPENSSL_DH_H 1

/* Define to 1 if you have the <openssl/evp.h> header file. */
#define HAVE_OPENSSL_EVP_H 1

/* Define to 1 if you have the <openssl/hmac.h> header file. */
#define HAVE_OPENSSL_HMAC_H 1

/* Define to 1 if you have the <osreldate.h> header file. */
/* #undef HAVE_OSRELDATE_H */

/* Define to 1 if you have the <pcap/pcap.h> header file. */
/* #undef HAVE_PCAP_PCAP_H */

/* define if you have pci_lookup_name() */
#define HAVE_PCI_LOOKUP_NAME 1

/* Define to 1 if you have the <pci/pci.h> header file. */
#define HAVE_PCI_PCI_H 1

/* Define to 1 if you have <pcre.h>. */
/* #undef HAVE_PCRE_H */

/* on aix, if you have perfstat */
/* #undef HAVE_PERFSTAT */

/* Define to 1 if you have `the perl_eval_pv' function. */
/* #undef HAVE_PERL_EVAL_PV_LC */

/* Define to 1 if you have the `Perl_eval_pv' function. */
#define HAVE_PERL_EVAL_PV_UC 1

/* Define to 1 if you have the <picl.h> header file. */
/* #undef HAVE_PICL_H */

/* define if you have pkginfo */
/* #undef HAVE_PKGINFO */

/* Define to 1 if you have the <pkginfo.h> header file. */
/* #undef HAVE_PKGINFO_H */

/* Define to 1 if you have the <pkglocs.h> header file. */
/* #undef HAVE_PKGLOCS_H */

/* Define to 1 if you have the <pkg.h> header file. */
/* #undef HAVE_PKG_H */

/* Define to 1 if you have the `poll' function. */
#define HAVE_POLL 1

/* Define to 1 if you have the `posix_spawn' function. */
#define HAVE_POSIX_SPAWN 1

/* Define to 1 if you have the `pread64' function. */
#define HAVE_PREAD64 1

/* Set if /etc/printcap exists */
/* #undef HAVE_PRINTCAP */

/* Define if prioritynames variable is declared in <syslog.h> */
#define HAVE_PRIORITYNAMES 1

/* Define to 1 if you have the <process.h> header file. */
/* #undef HAVE_PROCESS_H */

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H 1

/* Define to 1 if you have the `rand' function. */
#define HAVE_RAND 1

/* Define to 1 if you have the `random' function. */
#define HAVE_RANDOM 1

/* Define to 1 if you have the `readdir' function. */
#define HAVE_READDIR 1

/* Define to 1 if you have the `regcomp' function. */
#define HAVE_REGCOMP 1

/* Define to 1 if you have the <regex.h> header file. */
#define HAVE_REGEX_H 1

/* Define to 1 if you have the `rpmGetPath' function. */
/* #undef HAVE_RPMGETPATH */

/* Define to 1 if you have the <rpm/header.h> header file. */
/* #undef HAVE_RPM_HEADER_H */

/* Define to 1 if you have the <rpm/rpmfileutil.h> header file. */
/* #undef HAVE_RPM_RPMFILEUTIL_H */

/* Define to 1 if you have the <rpm/rpmlib.h> header file. */
/* #undef HAVE_RPM_RPMLIB_H */

/* Define to 1 if you have the <rpm/rpmts.h> header file. */
/* #undef HAVE_RPM_RPMTS_H */

/* Define if timezone declared as a scalar in <time.h> */
#define HAVE_SCALAR_TIMEZONE 1

/* Define to 1 if you have the <search.h> header file. */
#define HAVE_SEARCH_H 1

/* Define to 1 if you have the <security/cryptoki.h> header file. */
/* #undef HAVE_SECURITY_CRYPTOKI_H */

/* Define to 1 if you have the `select' function. */
#define HAVE_SELECT 1

/* Define to 1 if you have the <sensors/sensors.h> header file. */
#define HAVE_SENSORS_SENSORS_H 1

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `setfsent' function. */
#define HAVE_SETFSENT 1

/* Define to 1 if you have the `setgid' function. */
#define HAVE_SETGID 1

/* Define to 1 if you have the `setgroups' function. */
#define HAVE_SETGROUPS 1

/* Define to 1 if you have the `setitimer' function. */
#define HAVE_SETITIMER 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the `setmntent' function. */
#define HAVE_SETMNTENT 1

/* Define to 1 if you have the `setsid' function. */
#define HAVE_SETSID 1

/* Define to 1 if you have the `setuid' function. */
#define HAVE_SETUID 1

/* Define to 1 if you have the <sgtty.h> header file. */
#define HAVE_SGTTY_H 1

/* Define to 1 if you have the `sigaction' function. */
#define HAVE_SIGACTION 1

/* Define to 1 if you have the `sigalrm' function. */
/* #undef HAVE_SIGALRM */

/* Define to 1 if you have the `sigblock' function. */
#define HAVE_SIGBLOCK 1

/* Define if SIGHUP is defined in <signal.h>. */
#define HAVE_SIGHUP 1

/* Define to 1 if you have the `signal' function. */
#define HAVE_SIGNAL 1

/* Define to 1 if you have the `sigprocmask' function. */
#define HAVE_SIGPROCMASK 1

/* Define to 1 if you have the `sigset' function. */
#define HAVE_SIGSET 1

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define to 1 if you have the `socket' function. */
#define HAVE_SOCKET 1

/* Define to 1 if the system has the type `socklen_t'. */
#define HAVE_SOCKLEN_T 1

/* Define to 1 if SO_BINDTODEVICE is available */
#define HAVE_SO_BINDTODEVICE 1

/* Define to 1 if you have the <spawn.h> header file. */
#define HAVE_SPAWN_H 1

/* Define to 1 if you have the `srand' function. */
#define HAVE_SRAND 1

/* Define to 1 if you have the `srand48' function. */
#define HAVE_SRAND48 1

/* Define to 1 if you have the `srandom' function. */
#define HAVE_SRANDOM 1

/* Define to 1 if the system has the type `ssize_t'. */
#define HAVE_SSIZE_T 1

/* Define to 1 if you have the `SSL_library_init' function. */
/* #undef HAVE_SSL_LIBRARY_INIT */

/* Define to 1 if you have the `SSL_load_error_strings' function. */
/* #undef HAVE_SSL_LOAD_ERROR_STRINGS */

/* Define to 1 if you have the `statfs' function. */
#define HAVE_STATFS 1

/* Define to 1 if you have the `statvfs' function. */
#define HAVE_STATVFS 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `stime' function. */
/* #undef HAVE_STIME */

/* Define to 1 if you have the `strcasestr' function. */
#define HAVE_STRCASESTR 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcat' function. */
/* #undef HAVE_STRLCAT */

/* Define to 1 if you have the `strlcpy' function. */
/* #undef HAVE_STRLCPY */

/* Define to 1 if you have the `strncasecmp' function. */
#define HAVE_STRNCASECMP 1

/* Define to 1 if you have the `strtok_r' function. */
#define HAVE_STRTOK_R 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the `strtoul' function. */
#define HAVE_STRTOUL 1

/* Define to 1 if you have the `strtoull' function. */
#define HAVE_STRTOULL 1

/* Define to 1 if `at_next' is a member of `struct arphd'. */
/* #undef HAVE_STRUCT_ARPHD_AT_NEXT */

/* Define to 1 if `weak_key' is a member of `struct des_ks_struct'. */
/* #undef HAVE_STRUCT_DES_KS_STRUCT_WEAK_KEY */

/* Define to 1 if `d_type' is a member of `struct dirent'. */
#define HAVE_STRUCT_DIRENT_D_TYPE 1

/* Define to 1 if `speed_hi' is a member of `struct ethtool_cmd'. */
#define HAVE_STRUCT_ETHTOOL_CMD_SPEED_HI 1

/* Define to 1 if `ifa_next' is a member of `struct ifaddr'. */
#define HAVE_STRUCT_IFADDR_IFA_NEXT 1

/* Define to 1 if `if_addrhead.tqh_first' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_ADDRHEAD_TQH_FIRST */

/* Define to 1 if `if_addrlist' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_ADDRLIST */

/* Define to 1 if `if_baudrate' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_BAUDRATE */

/* Define to 1 if `if_baudrate.ifs_value' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_BAUDRATE_IFS_VALUE */

/* Define to 1 if `if_ibytes' is a member of `struct ifnet'. */
#define HAVE_STRUCT_IFNET_IF_IBYTES 1

/* Define to 1 if `if_imcasts' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_IMCASTS */

/* Define to 1 if `if_iqdrops' is a member of `struct ifnet'. */
#define HAVE_STRUCT_IFNET_IF_IQDROPS 1

/* Define to 1 if `if_lastchange.tv_nsec' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_LASTCHANGE_TV_NSEC */

/* Define to 1 if `if_lastchange.tv_sec' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_LASTCHANGE_TV_SEC */

/* Define to 1 if `if_mtu' is a member of `struct ifnet'. */
#define HAVE_STRUCT_IFNET_IF_MTU 1

/* Define to 1 if `if_noproto' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_NOPROTO */

/* Define to 1 if `if_obytes' is a member of `struct ifnet'. */
#define HAVE_STRUCT_IFNET_IF_OBYTES 1

/* Define to 1 if `if_omcasts' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_OMCASTS */

/* Define to 1 if `if_speed' is a member of `struct ifnet'. */
#define HAVE_STRUCT_IFNET_IF_SPEED 1

/* Define to 1 if `if_type' is a member of `struct ifnet'. */
#define HAVE_STRUCT_IFNET_IF_TYPE 1

/* Define to 1 if `if_xname' is a member of `struct ifnet'. */
/* #undef HAVE_STRUCT_IFNET_IF_XNAME */

/* Define to 1 if `ia_subnetmask' is a member of `struct in_ifaddr'. */
/* #undef HAVE_STRUCT_IN_IFADDR_IA_SUBNETMASK */

/* Define to 1 if `ipi_spec_dst' is a member of `struct in_pktinfo'. */
#define HAVE_STRUCT_IN_PKTINFO_IPI_SPEC_DST 1

/* Define to 1 if `ip6s_exthdrtoolong ' is a member of `struct ip6stat'. */
/* #undef HAVE_STRUCT_IP6STAT_IP6S_EXTHDRTOOLONG_ */

/* Define to 1 if `ips_cantforward' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_CANTFORWARD */

/* Define to 1 if `ips_cantfrag' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_CANTFRAG */

/* Define to 1 if `ips_delivered' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_DELIVERED */

/* Define to 1 if `ips_fragdropped' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_FRAGDROPPED */

/* Define to 1 if `ips_fragmented' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_FRAGMENTED */

/* Define to 1 if `ips_fragtimeout' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_FRAGTIMEOUT */

/* Define to 1 if `ips_localout' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_LOCALOUT */

/* Define to 1 if `ips_noproto' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_NOPROTO */

/* Define to 1 if `ips_noroute' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_NOROUTE */

/* Define to 1 if `ips_odropped' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_ODROPPED */

/* Define to 1 if `ips_ofragments' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_OFRAGMENTS */

/* Define to 1 if `ips_reassembled' is a member of `struct ipstat'. */
/* #undef HAVE_STRUCT_IPSTAT_IPS_REASSEMBLED */

/* Define to 1 if `m_clfree' is a member of `struct mbstat'. */
/* #undef HAVE_STRUCT_MBSTAT_M_CLFREE */

/* Define to 1 if `m_clusters' is a member of `struct mbstat'. */
/* #undef HAVE_STRUCT_MBSTAT_M_CLUSTERS */

/* Define to 1 if `m_mbufs' is a member of `struct mbstat'. */
/* #undef HAVE_STRUCT_MBSTAT_M_MBUFS */

/* Define to 1 if `n_value' is a member of `struct nlist64'. */
/* #undef HAVE_STRUCT_NLIST64_N_VALUE */

/* Define to 1 if `n_value' is a member of `struct nlist'. */
/* #undef HAVE_STRUCT_NLIST_N_VALUE */

/* Define to 1 if `rt_dst' is a member of `struct rtentry'. */
#define HAVE_STRUCT_RTENTRY_RT_DST 1

/* Define to 1 if `rt_hash' is a member of `struct rtentry'. */
/* #undef HAVE_STRUCT_RTENTRY_RT_HASH */

/* Define to 1 if `rt_next' is a member of `struct rtentry'. */
/* #undef HAVE_STRUCT_RTENTRY_RT_NEXT */

/* Define to 1 if `rt_refcnt' is a member of `struct rtentry'. */
/* #undef HAVE_STRUCT_RTENTRY_RT_REFCNT */

/* Define to 1 if `rt_unit' is a member of `struct rtentry'. */
/* #undef HAVE_STRUCT_RTENTRY_RT_UNIT */

/* Define to 1 if `rt_use' is a member of `struct rtentry'. */
/* #undef HAVE_STRUCT_RTENTRY_RT_USE */

/* Define to 1 if `sa_sigaction' is a member of `struct sigaction'. */
#define HAVE_STRUCT_SIGACTION_SA_SIGACTION 1

/* Define to 1 if `sin6_scope_id' is a member of `struct sockaddr_in6'. */
#define HAVE_STRUCT_SOCKADDR_IN6_SIN6_SCOPE_ID 1

/* Define to 1 if `sa_len' is a member of `struct sockaddr'. */
/* #undef HAVE_STRUCT_SOCKADDR_SA_LEN */

/* Define to 1 if `sa_union.sa_generic.sa_family2' is a member of `struct
   sockaddr'. */
/* #undef HAVE_STRUCT_SOCKADDR_SA_UNION_SA_GENERIC_SA_FAMILY2 */

/* Define to 1 if `ss_family' is a member of `struct sockaddr_storage'. */
#define HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY 1

/* Define to 1 if `__ss_family' is a member of `struct sockaddr_storage'. */
/* #undef HAVE_STRUCT_SOCKADDR_STORAGE___SS_FAMILY */

/* Define to 1 if `f_favail' is a member of `struct statfs'. */
/* #undef HAVE_STRUCT_STATFS_F_FAVAIL */

/* Define to 1 if `f_ffree' is a member of `struct statfs'. */
#define HAVE_STRUCT_STATFS_F_FFREE 1

/* Define to 1 if `f_files' is a member of `struct statfs'. */
#define HAVE_STRUCT_STATFS_F_FILES 1

/* Define to 1 if `f_flags' is a member of `struct statfs'. */
#define HAVE_STRUCT_STATFS_F_FLAGS 1

/* Define to 1 if `f_frsize' is a member of `struct statfs'. */
#define HAVE_STRUCT_STATFS_F_FRSIZE 1

/* Define to 1 if `f_files' is a member of `struct statvfs'. */
#define HAVE_STRUCT_STATVFS_F_FILES 1

/* Define to 1 if `f_frsize' is a member of `struct statvfs'. */
#define HAVE_STRUCT_STATVFS_F_FRSIZE 1

/* Define to 1 if `mnt_dir' is a member of `struct statvfs'. */
/* #undef HAVE_STRUCT_STATVFS_MNT_DIR */

/* Define to 1 if `sw_nblksenabled' is a member of `struct swdevt'. */
/* #undef HAVE_STRUCT_SWDEVT_SW_NBLKSENABLED */

/* Define to 1 if `tcp_rcvmemdrop' is a member of `struct tcpstat'. */
/* #undef HAVE_STRUCT_TCPSTAT_TCP_RCVMEMDROP */

/* Define to 1 if `tz_dsttime' is a member of `struct timezone'. */
#define HAVE_STRUCT_TIMEZONE_TZ_DSTTIME 1

/* Define to 1 if `tm_gmtoff' is a member of `struct tm'. */
#define HAVE_STRUCT_TM_TM_GMTOFF 1

/* Define to 1 if `tm_isdst' is a member of `struct tm'. */
#define HAVE_STRUCT_TM_TM_ISDST 1

/* Define to 1 if `udps_discard' is a member of `struct udpstat'. */
/* #undef HAVE_STRUCT_UDPSTAT_UDPS_DISCARD */

/* Define to 1 if `udps_fullsock' is a member of `struct udpstat'. */
/* #undef HAVE_STRUCT_UDPSTAT_UDPS_FULLSOCK */

/* Define to 1 if `udps_ipackets' is a member of `struct udpstat'. */
/* #undef HAVE_STRUCT_UDPSTAT_UDPS_IPACKETS */

/* Define to 1 if `udps_noport' is a member of `struct udpstat'. */
/* #undef HAVE_STRUCT_UDPSTAT_UDPS_NOPORT */

/* Define to 1 if `udps_noportbcast' is a member of `struct udpstat'. */
/* #undef HAVE_STRUCT_UDPSTAT_UDPS_NOPORTBCAST */

/* Define to 1 if `udps_opackets' is a member of `struct udpstat'. */
/* #undef HAVE_STRUCT_UDPSTAT_UDPS_OPACKETS */

/* Define to 1 if `pgswapin' is a member of `struct uvmexp'. */
/* #undef HAVE_STRUCT_UVMEXP_PGSWAPIN */

/* Define to 1 if you have the `sysconf' function. */
#define HAVE_SYSCONF 1

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H 1

/* Define to 1 if you have the `system' function. */
#define HAVE_SYSTEM 1

/* Define to 1 if you have the <sys/cdefs.h> header file. */
#define HAVE_SYS_CDEFS_H 1

/* Define to 1 if you have the <sys/conf.h> header file. */
/* #undef HAVE_SYS_CONF_H */

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/diskio.h> header file. */
/* #undef HAVE_SYS_DISKIO_H */

/* Define to 1 if you have the <sys/disklabel.h> header file. */
/* #undef HAVE_SYS_DISKLABEL_H */

/* Define to 1 if you have the <sys/dkio.h> header file. */
/* #undef HAVE_SYS_DKIO_H */

/* Define to 1 if you have the <sys/dkstat.h> header file. */
/* #undef HAVE_SYS_DKSTAT_H */

/* Define to 1 if you have the <sys/dmap.h> header file. */
/* #undef HAVE_SYS_DMAP_H */

/* Define to 1 if you have the <sys/file.h> header file. */
#define HAVE_SYS_FILE_H 1

/* Define to 1 if you have the <sys/filio.h> header file. */
/* #undef HAVE_SYS_FILIO_H */

/* Define to 1 if you have the <sys/fixpoint.h> header file. */
/* #undef HAVE_SYS_FIXPOINT_H */

/* Define to 1 if you have the <sys/fs.h> header file. */
/* #undef HAVE_SYS_FS_H */

/* Define to 1 if you have the <sys/hashing.h> header file. */
/* #undef HAVE_SYS_HASHING_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/loadavg.h> header file. */
/* #undef HAVE_SYS_LOADAVG_H */

/* Define to 1 if you have the <sys/mbuf.h> header file. */
/* #undef HAVE_SYS_MBUF_H */

/* Define to 1 if you have the <sys/mntent.h> header file. */
/* #undef HAVE_SYS_MNTENT_H */

/* Define to 1 if you have the <sys/mnttab.h> header file. */
/* #undef HAVE_SYS_MNTTAB_H */

/* Define to 1 if you have the <sys/mount.h> header file. */
#define HAVE_SYS_MOUNT_H 1

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/poll.h> header file. */
#define HAVE_SYS_POLL_H 1

/* Define to 1 if you have the <sys/pool.h> header file. */
/* #undef HAVE_SYS_POOL_H */

/* Define to 1 if you have the <sys/proc.h> header file. */
/* #undef HAVE_SYS_PROC_H */

/* Define to 1 if you have the <sys/protosw.h> header file. */
/* #undef HAVE_SYS_PROTOSW_H */

/* Define to 1 if you have the <sys/pstat.h> header file. */
/* #undef HAVE_SYS_PSTAT_H */

/* Define to 1 if you have the <sys/queue.h> header file. */
#define HAVE_SYS_QUEUE_H 1

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/sema.h> header file. */
/* #undef HAVE_SYS_SEMA_H */

/* Define to 1 if you have the <sys/socketvar.h> header file. */
#define HAVE_SYS_SOCKETVAR_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/sockio.h> header file. */
/* #undef HAVE_SYS_SOCKIO_H */

/* Define to 1 if you have the <sys/statfs.h> header file. */
#define HAVE_SYS_STATFS_H 1

/* Define to 1 if you have the <sys/statvfs.h> header file. */
#define HAVE_SYS_STATVFS_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/stream.h> header file. */
/* #undef HAVE_SYS_STREAM_H */

/* Define to 1 if you have the <sys/swap.h> header file. */
#define HAVE_SYS_SWAP_H 1

/* Define to 1 if you have the <sys/sysctl.h> header file. */
/* #undef HAVE_SYS_SYSCTL_H */

/* Define to 1 if you have the <sys/sysget.h> header file. */
/* #undef HAVE_SYS_SYSGET_H */

/* Define to 1 if you have the <sys/syslog.h> header file. */
#define HAVE_SYS_SYSLOG_H 1

/* Define to 1 if you have the <sys/sysmacros.h> header file. */
#define HAVE_SYS_SYSMACROS_H 1

/* Define to 1 if you have the <sys/sysmp.h> header file. */
/* #undef HAVE_SYS_SYSMP_H */

/* Define to 1 if you have the <sys/systemcfg.h> header file. */
/* #undef HAVE_SYS_SYSTEMCFG_H */

/* Define to 1 if you have the <sys/systeminfo.h> header file. */
/* #undef HAVE_SYS_SYSTEMINFO_H */

/* Define to 1 if you have the <sys/tcpipstats.h> header file. */
/* #undef HAVE_SYS_TCPIPSTATS_H */

/* Define to 1 if you have the <sys/timeb.h> header file. */
#define HAVE_SYS_TIMEB_H 1

/* Define to 1 if you have the <sys/timeout.h> header file. */
/* #undef HAVE_SYS_TIMEOUT_H */

/* Define to 1 if you have the <sys/times.h> header file. */
#define HAVE_SYS_TIMES_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/uio.h> header file. */
#define HAVE_SYS_UIO_H 1

/* Define to 1 if you have the <sys/un.h> header file. */
#define HAVE_SYS_UN_H 1

/* Define to 1 if you have the <sys/user.h> header file. */
#define HAVE_SYS_USER_H 1

/* Define to 1 if you have the <sys/utsname.h> header file. */
#define HAVE_SYS_UTSNAME_H 1

/* Define to 1 if you have the <sys/vfs.h> header file. */
#define HAVE_SYS_VFS_H 1

/* Define to 1 if you have the <sys/vmmac.h> header file. */
/* #undef HAVE_SYS_VMMAC_H */

/* Define to 1 if you have the <sys/vmmeter.h> header file. */
/* #undef HAVE_SYS_VMMETER_H */

/* Define to 1 if you have the <sys/vmparam.h> header file. */
/* #undef HAVE_SYS_VMPARAM_H */

/* Define to 1 if you have the <sys/vmsystm.h> header file. */
/* #undef HAVE_SYS_VMSYSTM_H */

/* Define to 1 if you have the <sys/vm.h> header file. */
/* #undef HAVE_SYS_VM_H */

/* Define to 1 if you have the <sys/vnode.h> header file. */
/* #undef HAVE_SYS_VNODE_H */

/* Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible. */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if you have the `tcgetattr' function. */
#define HAVE_TCGETATTR 1

/* Define to 1 if you have the `times' function. */
#define HAVE_TIMES 1

/* Define to 1 if you have the `TLSv1_method' function. */
#define HAVE_TLSV1_METHOD 1

/* Define to 1 if you have the `TLS_method' function. */
#define HAVE_TLS_METHOD 1

/* Define to 1 if you have the <ufs/ffs/fs.h> header file. */
/* #undef HAVE_UFS_FFS_FS_H */

/* Define to 1 if you have the <ufs/fs.h> header file. */
/* #undef HAVE_UFS_FS_H */

/* Define to 1 if you have the <ufs/ufs/dinode.h> header file. */
/* #undef HAVE_UFS_UFS_DINODE_H */

/* Define to 1 if you have the <ufs/ufs/inode.h> header file. */
/* #undef HAVE_UFS_UFS_INODE_H */

/* Define to 1 if you have the <ufs/ufs/quota.h> header file. */
/* #undef HAVE_UFS_UFS_QUOTA_H */

/* Define to 1 if the system has the type `uintmax_t'. */
#define HAVE_UINTMAX_T 1

/* Define to 1 if the system has the type `uintptr_t'. */
#define HAVE_UINTPTR_T 1

/* Define to 1 if you have the `uname' function. */
#define HAVE_UNAME 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if the system has the type `unsigned long long int'. */
#define HAVE_UNSIGNED_LONG_LONG_INT 1

/* Define to 1 if you have the `usleep' function. */
#define HAVE_USLEEP 1

/* Define to 1 if you have the <utmpx.h> header file. */
#define HAVE_UTMPX_H 1

/* Define to 1 if you have the <utsname.h> header file. */
/* #undef HAVE_UTSNAME_H */

/* Define to 1 if you have the <uvm/uvm_extern.h> header file. */
/* #undef HAVE_UVM_UVM_EXTERN_H */

/* Define to 1 if you have the <uvm/uvm_param.h> header file. */
/* #undef HAVE_UVM_UVM_PARAM_H */

/* Define to 1 if you have the <valgrind/memcheck.h> header file. */
/* #undef HAVE_VALGRIND_MEMCHECK_H */

/* Define to 1 if you have the <valgrind/valgrind.h> header file. */
/* #undef HAVE_VALGRIND_VALGRIND_H */

/* Define to 1 if you have the <validator/validator-config.h> header file. */
/* #undef HAVE_VALIDATOR_VALIDATOR_CONFIG_H */

/* Define to 1 if you have the `vm_region' function. */
/* #undef HAVE_VM_REGION */

/* Define to 1 if you have the `vm_region_64' function. */
/* #undef HAVE_VM_REGION_64 */

/* Define to 1 if you have the <vm/swap_pager.h> header file. */
/* #undef HAVE_VM_SWAP_PAGER_H */

/* Define to 1 if you have the <vm/vm_extern.h> header file. */
/* #undef HAVE_VM_VM_EXTERN_H */

/* Define to 1 if you have the <vm/vm.h> header file. */
/* #undef HAVE_VM_VM_H */

/* Define to 1 if you have the <vm/vm_param.h> header file. */
/* #undef HAVE_VM_VM_PARAM_H */

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* Define to 1 if you have the `waitpid' function. */
#define HAVE_WAITPID 1

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define to 1 if you have the <windows.h> header file. */
/* #undef HAVE_WINDOWS_H */

/* Define to 1 if you have the <winsock2.h> header file. */
/* #undef HAVE_WINSOCK2_H */

/* Define to 1 if you have the <winsock.h> header file. */
/* #undef HAVE_WINSOCK_H */

/* Define to 1 if you have the <ws2tcpip.h> header file. */
/* #undef HAVE_WS2TCPIP_H */

/* Define to 1 if you have the `X509_get_signature_nid' function. */
#define HAVE_X509_GET_SIGNATURE_NID 1

/* Define to 1 if you have the `X509_NAME_ENTRY_get_data' function. */
#define HAVE_X509_NAME_ENTRY_GET_DATA 1

/* Define to 1 if you have the `X509_NAME_ENTRY_get_object' function. */
#define HAVE_X509_NAME_ENTRY_GET_OBJECT 1

/* Define to 1 if you have the <xti.h> header file. */
/* #undef HAVE_XTI_H */

/* Define if _beginthreadex() is defined in <process.h> */
/* #undef HAVE__BEGINTHREADEX */

/* Define if _cputs() is defined in <conio.h> */
/* #undef HAVE__CPUTS */

/* Define if _getch() is defined in <conio.h> */
/* #undef HAVE__GETCH */

/* Define if _get_osfhandle() is defined in <io.h> */
/* #undef HAVE__GET_OSFHANDLE */

/* Define to 1 if you have the `_NSGetArgv' function. */
/* #undef HAVE__NSGETARGV */

/* Define to 1 if you have the `_NSGetExecutablePath' function. */
/* #undef HAVE__NSGETEXECUTABLEPATH */

/* Define if _open_osfhandle() is defined in <io.h> */
/* #undef HAVE__OPEN_OSFHANDLE */

/* location of UNIX kernel */
#define KERNEL_LOC "unknown"

/* Path to the lpstat command */
/* #undef LPSTAT_PATH */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* define if agentx transport is to use domain sockets only */
/* #undef NETSNMP_AGENTX_DOM_SOCK_ONLY */

/* Unix domain socket for AgentX master-subagent communication */
#define NETSNMP_AGENTX_SOCKET "/var/agentx/master"

/* Used to make the compiler issue a warning about deprecated functions and
   variables */
#define NETSNMP_ATTRIBUTE_DEPRECATED __attribute__((deprecated))

/* Used to suppress compiler warnings about unused functions and variables */
#define NETSNMP_ATTRIBUTE_UNUSED __attribute__((unused))

/* Define if static inline functions are unsupported */
/* #undef NETSNMP_BROKEN_INLINE */

/* "Define if crytography support is possible" */
#define NETSNMP_CAN_DO_CRYPTO 1

/* sysctl works to get boottime, etc... */
/* #undef NETSNMP_CAN_USE_SYSCTL */

/* configure options specified */
#define NETSNMP_CONFIGURE_OPTIONS " '--build=x86_64-linux-gnu' '--includedir=${prefix}/include' '--mandir=${prefix}/share/man' '--infodir=${prefix}/share/info' '--localstatedir=/var' '--disable-option-checking' '--disable-silent-rules' '--libdir=${prefix}/lib/x86_64-linux-gnu' '--runstatedir=/run' '--disable-maintainer-mode' '--disable-dependency-tracking' '--prefix=/usr' '--sysconfdir=/etc' '--mandir=/usr/share/man' '--with-persistent-directory=/var/lib/snmp' '--enable-ucd-snmp-compatibility' '--with-cflags=-g -O2 -ffile-prefix-map=/build/net-snmp-m72y6Y/net-snmp-5.9.1+dfsg=. -flto=auto -ffat-lto-objects -flto=auto -ffat-lto-objects -fstack-protector-strong -Wformat -Werror=format-security -DNETSNMP_USE_INLINE' '--with-ldflags=-Wl,-Bsymbolic-functions -flto=auto -ffat-lto-objects -flto=auto -Wl,-z,relro -Wl,-z,now' '--with-perl-modules=INSTALLDIRS=vendor' '--enable-as-needed' '--with-logfile=none' '--without-rpm' '--with-libwrap' '--with-openssl' '--without-dmalloc' '--without-efence' '--without-rsaref' '--with-sys-contact=root' '--with-sys-location=Unknown' '--with-mib-modules=smux ucd-snmp/dlmod mibII/mta_sendmail disman/event-mib ucd-snmp/diskio ucd-snmp/lmsensorsMib etherlike-mib/dot3StatsTable host' '--with-out-mib-modules=' '--with-transports=TLSTCP DTLSUDP' '--with-security-modules=tsm' '--enable-mfd-rewrites' '--with-mnttab=/etc/mtab' '--with-mibdirs=$HOME/.snmp/mibs:/usr/share/snmp/mibs:/usr/share/snmp/mibs/iana:/usr/share/snmp/mibs/ietf' '--with-mysql' '--with-systemd' '--enable-blumenthal-aes' 'UNAMEPROG=/bin/uname' 'PSPROG=/bin/ps' '--with-defaults' 'build_alias=x86_64-linux-gnu' 'CFLAGS=-g -O2 -ffile-prefix-map=/build/net-snmp-m72y6Y/net-snmp-5.9.1+dfsg=. -flto=auto -ffat-lto-objects -flto=auto -ffat-lto-objects -fstack-protector-strong -Wformat -Werror=format-security' 'LDFLAGS=-Wl,-Bsymbolic-functions -flto=auto -ffat-lto-objects -flto=auto -Wl,-z,relro -Wl,-z,now' 'CPPFLAGS=-Wdate-time -D_FORTIFY_SOURCE=2'"

/* if defined daemons will use syslog when no log destination is defined */
/* #undef NETSNMP_DAEMONS_DEFAULT_LOG_SYSLOG */

/* default location to look for mibs to load using the above tokens and/or
   those in the MIBS envrionment variable */
#define NETSNMP_DEFAULT_MIBDIRS "$HOME/.snmp/mibs:/usr/share/snmp/mibs:/usr/share/snmp/mibs/iana:/usr/share/snmp/mibs/ietf"

/* default mib files to load, specified by path. */
/* #undef NETSNMP_DEFAULT_MIBFILES */

/* Define if no agent is built */
/* #undef NETSNMP_DISABLE_AGENT */

/* Define if no apps are built */
/* #undef NETSNMP_DISABLE_APPS */

/* Define if DES encryption should not be supported */
/* #undef NETSNMP_DISABLE_DES */

/* Define if MD5 authentication should not be supported */
/* #undef NETSNMP_DISABLE_MD5 */

/* Define if mib loading and parsing code should not be included */
/* #undef NETSNMP_DISABLE_MIB_LOADING */

/* Define if SNMP SET support should be disabled */
/* #undef NETSNMP_DISABLE_SET_SUPPORT */

/* Define if SNMPv1 code should not be included */
/* #undef NETSNMP_DISABLE_SNMPV1 */

/* Define if SNMPv2c code should not be included */
/* #undef NETSNMP_DISABLE_SNMPV2C */

/* Define if AES-192/AES-256 encryption should be supported */
#define NETSNMP_DRAFT_BLUMENTHAL_AES_04 1

/* Define if you are embedding perl in the main agent. */
#define NETSNMP_EMBEDDED_PERL 1

/* define if you want to enable IPv6 support */
#define NETSNMP_ENABLE_IPV6 1

/* define if you want to restrict SMUX connections to localhost by default */
/* #undef NETSNMP_ENABLE_LOCAL_SMUX */

/* Define if you want to build MFD module rewrites */
#define NETSNMP_ENABLE_MFD_REWRITES 1

/* define if you want to compile support for both authentication and privacy
   support. */
#define NETSNMP_ENABLE_SCAPI_AUTHPRIV 1

/* testing code sections. */
/* #undef NETSNMP_ENABLE_TESTING_CODE */

/* if defined always use default auth/priv protocol when creating usmUsers */
/* #undef NETSNMP_FORCE_SYSTEM_V3_AUTHPRIV */

/* Should evaluate to the name of the current function if defined */
#define NETSNMP_FUNCTION __func__

/* ifnet needs to have _KERNEL defined */
/* #undef NETSNMP_IFNET_NEEDS_KERNEL */

/* ifnet needs to have _KERNEL_STRUCTURES defined */
/* #undef NETSNMP_IFNET_NEEDS_KERNEL_STRUCTURES */

/* Type of the third argument of ioctlsocket() */
#define NETSNMP_IOCTLSOCKET_ARG void

/* Define if you want to remove all non-essential code features. */
/* #undef NETSNMP_MINIMAL_CODE */

/* Define if you want to only support sending notifications */
/* #undef NETSNMP_NOTIFY_ONLY */

/* Define to suppress inclusion of deprecated functions */
/* #undef NETSNMP_NO_DEPRECATED_FUNCTIONS */

/* If you don't want the agent to report on variables it doesn't have data for
   */
#define NETSNMP_NO_DUMMY_VALUES 1

/* If we don't want to use kmem. */
/* #undef NETSNMP_NO_KMEM_USAGE */

/* Define if you want to remove all listening support from the code */
/* #undef NETSNMP_NO_LISTEN_SUPPORT */

/* If you don't have root access don't exit upon kmem errors */
/* #undef NETSNMP_NO_ROOT_ACCESS */

/* If you don't want to integrate with systemd. */
/* #undef NETSNMP_NO_SYSTEMD */

/* Define if you want to remove all SET/write access from the code */
/* #undef NETSNMP_NO_WRITE_SUPPORT */

/* umask permissions to set up persistent files with */
#define NETSNMP_PERSISTENT_MASK 077

/* Size prefix to use to printf a size_t or ssize_t */
#define NETSNMP_PRIz "z"

/* Define to 1 if you want to build with reentrant/threaded code (incomplete).
   */
/* #undef NETSNMP_REENTRANT */

/* Type of the fifth argument of select() */
#define NETSNMP_SELECT_TIMEVAL struct timeval

/* define if you do not want snmptrapd to register as an AgentX subagent */
/* #undef NETSNMP_SNMPTRAPD_DISABLE_AGENTX */

/* Pattern of temporary files */
#define NETSNMP_TEMP_FILE_PATTERN "/tmp/snmpdXXXXXX"

/* "Define if internal cryptography code should be used" */
/* #undef NETSNMP_USE_INTERNAL_CRYPTO */

/* define if you are using the MD5 code ... */
/* #undef NETSNMP_USE_INTERNAL_MD5 */

/* Define this if you're using Heimdal Kerberos */
/* #undef NETSNMP_USE_KERBEROS_HEIMDAL */

/* Define this if we're using the new MIT crypto API */
/* #undef NETSNMP_USE_KERBEROS_MIT */

/* define if you are using the mysql code for snmptrapd ... */
#define NETSNMP_USE_MYSQL 1

/* Define if you are using the codeS11 library ... */
/* #undef NETSNMP_USE_PKCS11 */

/* Define this if you have lm_sensors v3 or later */
#define NETSNMP_USE_SENSORS_V3 1

/* Should we compile to use special opaque types: float, double, counter64,
   i64, ui64, union? */
#define NETSNMP_WITH_OPAQUE_SPECIAL_TYPES 1

/* Define to the address where bug reports for this package should be sent. */
#ifndef PACKAGE_BUGREPORT
#define PACKAGE_BUGREPORT "net-snmp-coders@lists.sourceforge.net"
#endif

/* Define to the full name of this package. */
#ifndef PACKAGE_NAME
#define PACKAGE_NAME "Net-SNMP"
#endif

/* Define to the full name and version of this package. */
#ifndef PACKAGE_STRING
#define PACKAGE_STRING "Net-SNMP 5.9.1"
#endif

/* Define to the one symbol short name of this package. */
#ifndef PACKAGE_TARNAME
#define PACKAGE_TARNAME "net-snmp"
#endif

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "5.9.1"
#endif

/* Command to generate ps output, the final column must be the process name
   withOUT arguments */
#define PSCMD "/bin/ps -e"

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* define rtentry to ortentry on SYSV machines (alphas) */
#define RTENTRY struct rtentry

/* Use BSD 4.4 routing table entries? */
/* #undef RTENTRY_4_4 */

/* Qualifier for second argument of the appverify_cookie_cb() callback
   function */
#define SECOND_APPVERIFY_COOKIE_CB_ARG_QUALIFIER const

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `intmax_t', as computed by sizeof. */
#define SIZEOF_INTMAX_T 8

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 8

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `sockaddr_un.sun_path', as computed by sizeof. */
#define SIZEOF_SOCKADDR_UN_SUN_PATH 108

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define if statfs takes 2 args and the second argument has type struct
   fs_data. [Ultrix] */
/* #undef STAT_STATFS_FS_DATA */

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#define STDC_HEADERS 1

/* define if SIOCGIFADDR exists in sys/ioctl.h */
#define SYS_IOCTL_H_HAS_SIOCGIFADDR 1

/* Define if the TCP timer constants in <netinet/tcp_timer.h> depend on the
   integer variable 'hz'. [FreeBSD 4.x] */
/* #undef TCPTV_NEEDS_HZ */

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. This
   macro is obsolete. */
#define TIME_WITH_SYS_TIME 1

/* Where is the uname command */
#define UNAMEPROG "/bin/uname"

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable general extensions on macOS.  */
#ifndef _DARWIN_C_SOURCE
# define _DARWIN_C_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable X/Open compliant socket functions that do not require linking
   with -lxnet on HP-UX 11.11.  */
#ifndef _HPUX_ALT_XOPEN_SOCKET_API
# define _HPUX_ALT_XOPEN_SOCKET_API 1
#endif
/* Identify the host operating system as Minix.
   This macro does not affect the system headers' behavior.
   A future release of Autoconf may stop defining this macro.  */
#ifndef _MINIX
/* # undef _MINIX */
#endif
/* Enable general extensions on NetBSD.
   Enable NetBSD compatibility extensions on Minix.  */
#ifndef _NETBSD_SOURCE
# define _NETBSD_SOURCE 1
#endif
/* Enable OpenBSD compatibility extensions on NetBSD.
   Oddly enough, this does nothing on OpenBSD.  */
#ifndef _OPENBSD_SOURCE
# define _OPENBSD_SOURCE 1
#endif
/* Define to 1 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_SOURCE
/* # undef _POSIX_SOURCE */
#endif
/* Define to 2 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_1_SOURCE
/* # undef _POSIX_1_SOURCE */
#endif
/* Enable POSIX-compatible threading on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-5:2014.  */
#ifndef __STDC_WANT_IEC_60559_ATTRIBS_EXT__
# define __STDC_WANT_IEC_60559_ATTRIBS_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-1:2014.  */
#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
# define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-2:2015.  */
#ifndef __STDC_WANT_IEC_60559_DFP_EXT__
# define __STDC_WANT_IEC_60559_DFP_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-4:2015.  */
#ifndef __STDC_WANT_IEC_60559_FUNCS_EXT__
# define __STDC_WANT_IEC_60559_FUNCS_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-3:2015.  */
#ifndef __STDC_WANT_IEC_60559_TYPES_EXT__
# define __STDC_WANT_IEC_60559_TYPES_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TR 24731-2:2010.  */
#ifndef __STDC_WANT_LIB_EXT2__
# define __STDC_WANT_LIB_EXT2__ 1
#endif
/* Enable extensions specified by ISO/IEC 24747:2009.  */
#ifndef __STDC_WANT_MATH_SPEC_FUNCS__
# define __STDC_WANT_MATH_SPEC_FUNCS__ 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable X/Open extensions.  Define to 500 only if necessary
   to make mbstate_t available.  */
#ifndef _XOPEN_SOURCE
/* # undef _XOPEN_SOURCE */
#endif


/* Define for Solaris 2.5.1 so the uint32_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT32_T */

/* Define for Solaris 2.5.1 so the uint64_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT64_T */

/* Define for Solaris 2.5.1 so the uint8_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
/* #undef _UINT8_T */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* in_addr_t definition if not defined in <netinet/in.h>. Must match the type
   of sockaddr_in::sin_addr */
/* #undef in_addr_t */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to the type of a signed integer type of width exactly 16 bits if
   such a type exists and the standard includes do not define it. */
/* #undef int16_t */

/* Define to the type of a signed integer type of width exactly 32 bits if
   such a type exists and the standard includes do not define it. */
/* #undef int32_t */

/* Define to the type of a signed integer type of width exactly 64 bits if
   such a type exists and the standard includes do not define it. */
/* #undef int64_t */

/* Define to the type of a signed integer type of width exactly 8 bits if such
   a type exists and the standard includes do not define it. */
/* #undef int8_t */

/* Define to the widest signed integer type if <stdint.h> and <inttypes.h> do
   not define. */
/* #undef intmax_t */

/* Define to the type of a signed integer type wide enough to hold a pointer,
   if such a type exists, and if the system does not define it. */
/* #undef intptr_t */

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */

/* Define as a signed integer type capable of holding a process identifier. */
/* #undef pid_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to the type of an unsigned integer type of width exactly 16 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint16_t */

/* Define to the type of an unsigned integer type of width exactly 32 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint32_t */

/* Define to the type of an unsigned integer type of width exactly 64 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint64_t */

/* Define to the type of an unsigned integer type of width exactly 8 bits if
   such a type exists and the standard includes do not define it. */
/* #undef uint8_t */

/* Define to the widest unsigned integer type if <stdint.h> and <inttypes.h>
   do not define. */
/* #undef uintmax_t */

/* Define to the type of an unsigned integer type wide enough to hold a
   pointer, if such a type exists, and if the system does not define it. */
/* #undef uintptr_t */

/* end of definitions added by configure on-the-fly */

/* If you have openssl 0.9.7 or above, you likely have AES support. */
#define NETSNMP_USE_OPENSSL 1
#if (defined(NETSNMP_USE_OPENSSL) && defined(HAVE_OPENSSL_AES_H) && defined(HAVE_AES_CFB128_ENCRYPT)) || defined(NETSNMP_USE_INTERNAL_CRYPTO)
#define HAVE_AES 1
#endif

/* define signal if DNE */

#ifndef HAVE_SIGNAL
#ifdef HAVE_SIGSET
#define signal(a,b) sigset(a,b)
#endif
#endif

#ifdef HAVE_DMALLOC_H
#define DMALLOC_FUNC_CHECK
#endif

#endif /* NETSNMP_NO_AUTOCONF_DEFINITIONS */

/*
 * Note: GCC 4.6 added __BYTE_ORDER__, __ORDER_BIG_ENDIAN__,
 * __ORDER_LITTLE_ENDIAN__ and __ORDER_PDP_ENDIAN__ in SVN r165881. For older
 * gcc versions and also for other compilers, determine the endianness using
 * an expression that can be evaluated at compile time. To do: add support for
 * other compilers than gcc that do not support statement expressions.
 */
#if defined(__BYTE_ORDER__)
# if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define NETSNMP_BIGENDIAN 1
# elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define NETSNMP_BIGENDIAN 0
# else
#  error Unknown byte order
# endif
#else
# define NETSNMP_BIGENDIAN                              \
    (__extension__                                      \
     ({                                                 \
         union { unsigned long l; unsigned char c; } u; \
                                                        \
         u.l = 1;                                       \
         u.c == 0;                                      \
     })                                                 \
    )
#endif




/* ********* NETSNMP_MARK_BEGIN_CLEAN_NAMESPACE ********* */
/* 
 * put all new net-snmp-specific definitions here
 *
 * all definitions MUST have a NETSNMP_ prefix
 *
 */

/* Default (SNMP) version number for the tools to use */
#define NETSNMP_DEFAULT_SNMP_VERSION 3

/* don't change these values! */
#define NETSNMP_SNMPV1      0xAAAA       /* readable by anyone */
#define NETSNMP_SNMPV2ANY   0xA000       /* V2 Any type (includes NoAuth) */
#define NETSNMP_SNMPV2AUTH  0x8000       /* V2 Authenticated requests only */

/* default list of mibs to load */
#define NETSNMP_DEFAULT_MIBS ":SNMPv2-MIB:IF-MIB:IP-MIB:TCP-MIB:UDP-MIB:HOST-RESOURCES-MIB:NOTIFICATION-LOG-MIB:DISMAN-EVENT-MIB:DISMAN-SCHEDULE-MIB:HOST-RESOURCES-TYPES:MTA-MIB:NETWORK-SERVICES-MIB:UCD-DISKIO-MIB:UCD-DLMOD-MIB:LM-SENSORS-MIB:UCD-SNMP-MIB:UCD-DEMO-MIB:SNMP-TARGET-MIB:NET-SNMP-AGENT-MIB:SNMP-FRAMEWORK-MIB:SNMP-MPD-MIB:SNMP-USER-BASED-SM-MIB:SNMP-VIEW-BASED-ACM-MIB:SNMP-COMMUNITY-MIB:IPV6-ICMP-MIB:IPV6-MIB:IPV6-TCP-MIB:IPV6-UDP-MIB:IP-FORWARD-MIB:NET-SNMP-PASS-MIB:NET-SNMP-EXTEND-MIB:SNMP-NOTIFICATION-MIB:SNMPv2-TM:NET-SNMP-VACM-MIB"

/* debugging stuff */
/* if defined, we optimize the code to exclude all debugging calls. */
/* #undef NETSNMP_NO_DEBUGGING */
/* ignore the -D flag and always print debugging information */
#define NETSNMP_ALWAYS_DEBUG 0

/* reverse encoding BER packets is both faster and more efficient in space. */
#define NETSNMP_USE_REVERSE_ASNENCODING       1
#define NETSNMP_DEFAULT_ASNENCODING_DIRECTION 1 /* 1 = reverse, 0 = forwards */

/* PERSISTENT_DIRECTORY: If defined, the library is capabile of saving
   persisant information to this directory in the form of configuration
   lines: PERSISTENT_DIRECTORY/NAME.persistent.conf */
#define NETSNMP_PERSISTENT_DIRECTORY "/var/lib/snmp"

/* AGENT_DIRECTORY_MODE: the mode the agents should use to create
   directories with. Since the data stored here is probably sensitive, it
   probably should be read-only by root/administrator. */
#define NETSNMP_AGENT_DIRECTORY_MODE 0700

/* MAX_PERSISTENT_BACKUPS:
 *   The maximum number of persistent backups the library will try to
 *   read from the persistent cache directory.  If an application fails to
 *   close down successfully more than this number of times, data will be lost.
 */
#define NETSNMP_MAX_PERSISTENT_BACKUPS 10

/* define the system type include file here */
#define NETSNMP_SYSTEM_INCLUDE_FILE "net-snmp/system/linux.h"

/* define the machine (cpu) type include file here */
#define NETSNMP_MACHINE_INCLUDE_FILE "net-snmp/machine/generic.h"

/* define the UDP buffer defaults undefined means use the OS buffers
 * by default */
/* #undef NETSNMP_DEFAULT_SERVER_SEND_BUF */
/* #undef NETSNMP_DEFAULT_SERVER_RECV_BUF */
/* #undef NETSNMP_DEFAULT_CLIENT_SEND_BUF */
/* #undef NETSNMP_DEFAULT_CLIENT_RECV_BUF */

/* net-snmp's major path names */
#define SNMPLIBPATH "/usr/lib/x86_64-linux-gnu/snmp"
#define SNMPSHAREPATH "/usr/share/snmp"
#define SNMPCONFPATH "/etc/snmp"
#define SNMPDLMODPATH "/usr/lib/x86_64-linux-gnu/snmp/dlmod"

/* NETSNMP_LOGFILE:  If defined it closes stdout/err/in and opens this in 
   out/err's place.  (stdin is closed so that sh scripts won't wait for it) */
/* #undef NETSNMP_LOGFILE */

/* default system contact */
#define NETSNMP_SYS_CONTACT "root"

/* system location */
#define NETSNMP_SYS_LOC "Unknown"

/* Use libwrap to handle allow/deny hosts? */
#define NETSNMP_USE_LIBWRAP 1

/* Mib-2 tree Info */
/* These are the system information variables. */

#define NETSNMP_VERS_DESC   "unknown"             /* overridden at run time */
#define NETSNMP_SYS_NAME    "unknown"             /* overridden at run time */

/* comment out the second define to turn off functionality for any of
   these: (See README for details) */

/*   proc PROCESSNAME [MAX] [MIN] */
#define NETSNMP_PROCMIBNUM 2

/*   exec/shell NAME COMMAND      */
#define NETSNMP_SHELLMIBNUM 8

/*   swap MIN                     */
#define NETSNMP_MEMMIBNUM 4

/*   disk DISK MINSIZE            */
#define NETSNMP_DISKMIBNUM 9

/*   load 1 5 15                  */
#define NETSNMP_LOADAVEMIBNUM 10

/* which version are you using? This mibloc will tell you */
#define NETSNMP_VERSIONMIBNUM 100

/* Reports errors the agent runs into */
/* (typically its "can't fork, no mem" problems) */
#define NETSNMP_ERRORMIBNUM 101

/* The sub id of EXTENSIBLEMIB returned to queries of
   .iso.org.dod.internet.mgmt.mib-2.system.sysObjectID.0 */
#define NETSNMP_AGENTID 250

/* This ID is returned after the AGENTID above.  IE, the resulting
   value returned by a query to sysObjectID is
   EXTENSIBLEMIB.AGENTID.???, where ??? is defined below by OSTYPE */

#define NETSNMP_HPUX9ID 1
#define NETSNMP_SUNOS4ID 2 
#define NETSNMP_SOLARISID 3
#define NETSNMP_OSFID 4
#define NETSNMP_ULTRIXID 5
#define NETSNMP_HPUX10ID 6
#define NETSNMP_NETBSD1ID 7
#define NETSNMP_FREEBSDID 8
#define NETSNMP_IRIXID 9
#define NETSNMP_LINUXID 10
#define NETSNMP_BSDIID 11
#define NETSNMP_OPENBSDID 12
#define NETSNMP_WIN32ID 13
#define NETSNMP_HPUX11ID 14
#define NETSNMP_AIXID 15
#define NETSNMP_MACOSXID 16
#define NETSNMP_DRAGONFLYID 17
#define NETSNMP_UNKNOWNID 255

#ifdef hpux9
#define NETSNMP_OSTYPE NETSNMP_HPUX9ID
#endif
#ifdef hpux10
#define NETSNMP_OSTYPE NETSNMP_HPUX10ID
#endif
#ifdef hpux11
#define NETSNMP_OSTYPE NETSNMP_HPUX11ID
#endif
#ifdef sunos4
#define NETSNMP_OSTYPE NETSNMP_SUNOS4ID
#endif
#ifdef solaris2
#define NETSNMP_OSTYPE NETSNMP_SOLARISID
#endif
#if defined(osf3) || defined(osf4) || defined(osf5)
#define NETSNMP_OSTYPE NETSNMP_OSFID
#endif
#ifdef ultrix4
#define NETSNMP_OSTYPE NETSNMP_ULTRIXID
#endif
#if defined(netbsd1) || defined(netbsd2)
#define NETSNMP_OSTYPE NETSNMP_NETBSD1ID
#endif
#if defined(__FreeBSD__)
#define NETSNMP_OSTYPE NETSNMP_FREEBSDID
#endif
#if defined(__DragonFly__)
#define NETSNMP_OSTYPE NETSNMP_DRAGONFLYID
#endif
#if defined(irix6) || defined(irix5)
#define NETSNMP_OSTYPE NETSNMP_IRIXID
#endif
#ifdef linux
#define NETSNMP_OSTYPE NETSNMP_LINUXID
#endif
#if defined(bsdi2) || defined(bsdi3) || defined(bsdi4)
#define NETSNMP_OSTYPE NETSNMP_BSDIID
#endif
#if defined(openbsd)
#define NETSNMP_OSTYPE NETSNMP_OPENBSDID
#endif
#ifdef WIN32
#define NETSNMP_OSTYPE NETSNMP_WIN32ID
#endif
#if defined(aix3) || defined(aix4) || defined(aix5) || defined(aix6) || defined(aix7)
#define NETSNMP_OSTYPE NETSNMP_AIXID
#endif
#if defined(darwin) && (darwin >= 8)
#define NETSNMP_OSTYPE NETSNMP_MACOSXID
#endif
/* unknown */
#ifndef NETSNMP_OSTYPE
#define NETSNMP_OSTYPE NETSNMP_UNKNOWNID
#endif

/* The enterprise number has been assigned by the IANA group.   */
/* Optionally, this may point to the location in the tree your  */
/* company/organization has been allocated.                     */
/* The assigned enterprise number for the NET_SNMP MIB modules. */
#define NETSNMP_ENTERPRISE_OID			8072
#define NETSNMP_ENTERPRISE_MIB			1,3,6,1,4,1,8072
#define NETSNMP_ENTERPRISE_DOT_MIB		1.3.6.1.4.1.8072
#define NETSNMP_ENTERPRISE_DOT_MIB_LENGTH	7

/* The assigned enterprise number for sysObjectID. */
#define NETSNMP_SYSTEM_MIB		1,3,6,1,4,1,8072,3,2,NETSNMP_OSTYPE
#define NETSNMP_SYSTEM_DOT_MIB		1.3.6.1.4.1.8072.3.2.NETSNMP_OSTYPE
#define NETSNMP_SYSTEM_DOT_MIB_LENGTH	10

/* The assigned enterprise number for notifications. */
#define NETSNMP_NOTIFICATION_MIB		1,3,6,1,4,1,8072,4
#define NETSNMP_NOTIFICATION_DOT_MIB		1.3.6.1.4.1.8072.4
#define NETSNMP_NOTIFICATION_DOT_MIB_LENGTH	8

/* this is the location of the ucdavis mib tree.  It shouldn't be
   changed, as the places it is used are expected to be constant
   values or are directly tied to the UCD-SNMP-MIB. */
#define NETSNMP_UCDAVIS_OID		2021
#define NETSNMP_UCDAVIS_MIB		1,3,6,1,4,1,2021
#define NETSNMP_UCDAVIS_DOT_MIB		1.3.6.1.4.1.2021
#define NETSNMP_UCDAVIS_DOT_MIB_LENGTH	7

/* how long to wait (seconds) for error querys before reseting the error trap.*/
#define NETSNMP_ERRORTIMELENGTH 600 

/* Exec command to fix PROC problems */
/* %s will be replaced by the process name in error */

/* #define NETSNMP_PROCFIXCMD "/usr/bin/perl /local/scripts/fixproc %s" */

/* Exec command to fix EXEC problems */
/* %s will be replaced by the exec/script name in error */

/* #define NETSNMP_EXECFIXCMD "/usr/bin/perl /local/scripts/fixproc %s" */

/* Should exec output Cashing be used (speeds up things greatly), and
   if so, After how many seconds should the cache re-newed?  Note:
   Don't define CASHETIME to disable cashing completely */

#define NETSNMP_EXCACHETIME 30
#define NETSNMP_CACHEFILE ".snmp-exec-cache"
#define NETSNMP_MAXCACHESIZE (1500*80)   /* roughly 1500 lines max */

/* misc defaults */

/* default of 100 meg minimum if the minimum size is not specified in
   the config file */
#define NETSNMP_DEFDISKMINIMUMSPACE 100000

/* default maximum load average before error */
#define NETSNMP_DEFMAXLOADAVE 12.0

/* max times to loop reading output from execs. */
/* Because of sleep(1)s, this will also be time to wait (in seconds) for exec
   to finish */
#define NETSNMP_MAXREADCOUNT 100

/* Set if snmpgets should block and never timeout */
/* The original CMU code had this hardcoded as = 1 */
#define NETSNMP_SNMPBLOCK 1

/* How long to wait before restarting the agent after a snmpset to
   EXTENSIBLEMIB.VERSIONMIBNUM.VERRESTARTAGENT.  This is
   necessary to finish the snmpset reply before restarting. */
#define NETSNMP_RESTARTSLEEP 5

/* UNdefine to allow specifying zero-length community string */
/* #define NETSNMP_NO_ZEROLENGTH_COMMUNITY 1 */

/* Number of community strings to store */
#define NETSNMP_NUM_COMMUNITIES	5

/* internal define */
#define NETSNMP_LASTFIELD -1

/*  Pluggable transports.  */

/*  This is defined if support for the UDP/IP transport domain is
    available.   */
#define NETSNMP_TRANSPORT_UDP_DOMAIN 1

/*  This is defined if support for the shared UDP/IP transport domain is
    available.   */
/* #undef NETSNMP_TRANSPORT_UDPSHARED_DOMAIN */

/*  This is defined if support for the "callback" transport domain is
    available.   */
#define NETSNMP_TRANSPORT_CALLBACK_DOMAIN 1

/*  This is defined if support for the TCP/IP transport domain is
    available.  */
#define NETSNMP_TRANSPORT_TCP_DOMAIN 1

/*  This is defined if support for the Unix transport domain
    (a.k.a. "local IPC") is available.  */
#define NETSNMP_TRANSPORT_UNIX_DOMAIN 1

/*  This is defined if support for the AAL5 PVC transport domain is
    available.  */
/* #undef NETSNMP_TRANSPORT_AAL5PVC_DOMAIN */

/*  This is defined if support for the IPX transport domain is
    available.  */
/* #undef NETSNMP_TRANSPORT_IPX_DOMAIN */

/*  This is defined if support for the UDP/IPv6 transport domain is
    available.  */
#define NETSNMP_TRANSPORT_UDPIPV6_DOMAIN 1

/*  This is defined if support for the TCP/IPv6 transport domain is
    available.  */
#define NETSNMP_TRANSPORT_TCPIPV6_DOMAIN 1

/*  This is defined if support for the TLS transport domain is
    available.   */
#define NETSNMP_TRANSPORT_TLSBASE_DOMAIN 1

/*  This is defined if support for the Alias transport domain is
    available.   */
#define NETSNMP_TRANSPORT_ALIAS_DOMAIN 1

/*  This is defined if support for the SSH transport domain is
    available.   */
/* #undef NETSNMP_TRANSPORT_SSH_DOMAIN */

/*  This is defined if support for the DTLS/UDP transport domain is
    available.   */
#define NETSNMP_TRANSPORT_DTLSUDP_DOMAIN 1

/*  This is defined if support for the TLS/TCP transport domain is
    available.   */
#define NETSNMP_TRANSPORT_TLSTCP_DOMAIN 1

/*  This is defined if support for stdin/out transport domain is available.   */
/* #undef NETSNMP_TRANSPORT_STD_DOMAIN */

/*  This is defined if support for the IPv4Base transport domain is available.   */
#define NETSNMP_TRANSPORT_IPV4BASE_DOMAIN 1

/* define this if the USM security module is available */
#define NETSNMP_SECMOD_USM 1

/* define this if the KSM (kerberos based snmp) security module is available */
/* #undef NETSNMP_SECMOD_KSM */

/* define this if the local security module is available */
/* #undef NETSNMP_SECMOD_LOCALSM */

/* define if configured as a "mini-agent" */
/* #undef NETSNMP_MINI_AGENT */

/* this is the location of the net-snmp mib tree.  It shouldn't be
   changed, as the places it is used are expected to be constant
   values or are directly tied to the UCD-SNMP-MIB. */
#define NETSNMP_OID		8072
#define NETSNMP_MIB		1,3,6,1,4,1,8072
#define NETSNMP_DOT_MIB		1.3.6.1.4.1.8072
#define NETSNMP_DOT_MIB_LENGTH	7

/* pattern for temporary file names */
#define NETSNMP_TEMP_FILE_PATTERN "/tmp/snmpdXXXXXX"

/*
 * this must be before the system/machine includes, to allow them to
 * override and turn off inlining. To do so, they should do the
 * following:
 *
 *    #undef NETSNMP_ENABLE_INLINE
 *    #define NETSNMP_ENABLE_INLINE 0
 *
 * A user having problems with their compiler can also turn off
 * the use of inline by defining NETSNMP_NO_INLINE via their cflags:
 *
 *    -DNETSNMP_NO_INLINE
 *
 * Header and source files should only test against NETSNMP_USE_INLINE:
 *
 *   #ifdef NETSNMP_USE_INLINE
 *   NETSNMP_INLINE function(int parm) { return parm -1; }
 *   #endif
 *
 * Functions which should be static, regardless of whether or not inline
 * is available or enabled should use the NETSNMP_STATIC_INLINE macro,
 * like so:
 *
 *    NETSNMP_STATIC_INLINE function(int parm) { return parm -1; }
 *
 * NOT like this:
 *
 *    static NETSNMP_INLINE function(int parm) { return parm -1; }
 *
 */
#ifdef NETSNMP_BROKEN_INLINE
#   define NETSNMP_ENABLE_INLINE 0
#else
#   define NETSNMP_ENABLE_INLINE 1
#endif

#include NETSNMP_SYSTEM_INCLUDE_FILE
#include NETSNMP_MACHINE_INCLUDE_FILE

#if NETSNMP_ENABLE_INLINE && !defined(NETSNMP_NO_INLINE)
#   define NETSNMP_USE_INLINE 1
#   ifndef NETSNMP_INLINE
#      define NETSNMP_INLINE __inline__
#   endif
#   ifndef NETSNMP_STATIC_INLINE
#      define NETSNMP_STATIC_INLINE static __inline__
#   endif
#else
#   define NETSNMP_INLINE 
#   define NETSNMP_STATIC_INLINE static
#endif

#ifndef NETSNMP_IMPORT
#  define NETSNMP_IMPORT extern
#endif

/* comment the next line if you are compiling with libsnmp.h 
   and are not using the UC-Davis SNMP library. */
#define UCD_SNMP_LIBRARY 1

/* final conclusion on nlist usage */
#if defined(HAVE_NLIST) && defined(HAVE_STRUCT_NLIST_N_VALUE) && !defined(NETSNMP_DONT_USE_NLIST) && !defined(NETSNMP_NO_KMEM_USAGE)
#define NETSNMP_CAN_USE_NLIST
#endif


/* ********* NETSNMP_MARK_BEGIN_LEGACY_DEFINITIONS *********/
/* 
 * existing definitions prior to Net-SNMP 5.4
 *
 * do not add anything new here
 *
 */

#ifndef NETSNMP_NO_LEGACY_DEFINITIONS

#ifdef NETSNMP_DEFAULT_SNMP_VERSION
# define DEFAULT_SNMP_VERSION NETSNMP_DEFAULT_SNMP_VERSION
#endif

#ifdef NETSNMP_SNMPV1
# define SNMPV1 NETSNMP_SNMPV1
#endif

#ifdef NETSNMP_SNMPV2ANY
# define SNMPV2ANY NETSNMP_SNMPV2ANY
#endif

#ifdef NETSNMP_SNMPV2AUTH
# define SNMPV2AUTH NETSNMP_SNMPV2AUTH
#endif

#ifdef NETSNMP_DEFAULT_MIBS
# define DEFAULT_MIBS NETSNMP_DEFAULT_MIBS
#endif

#ifdef NETSNMP_DEFAULT_MIBDIRS
# define DEFAULT_MIBDIRS NETSNMP_DEFAULT_MIBDIRS
#endif

#ifdef NETSNMP_DEFAULT_MIBFILES
# define DEFAULT_MIBFILES NETSNMP_DEFAULT_MIBFILES
#endif

#ifdef NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
# define OPAQUE_SPECIAL_TYPES NETSNMP_WITH_OPAQUE_SPECIAL_TYPES
#endif

#ifdef NETSNMP_ENABLE_SCAPI_AUTHPRIV
# define SCAPI_AUTHPRIV NETSNMP_ENABLE_SCAPI_AUTHPRIV
#endif

#ifdef NETSNMP_USE_INTERNAL_MD5
# define USE_INTERNAL_MD5 NETSNMP_USE_INTERNAL_MD5
#endif

#ifdef NETSNMP_USE_PKCS11
# define USE_PKCS NETSNMP_USE_PKCS11
#endif

#ifdef NETSNMP_USE_OPENSSL
# define USE_OPENSSL NETSNMP_USE_OPENSSL
#endif

#ifdef NETSNMP_NO_DEBUGGING
# define SNMP_NO_DEBUGGING NETSNMP_NO_DEBUGGING
#endif

#ifdef NETSNMP_ALWAYS_DEBUG
# define SNMP_ALWAYS_DEBUG NETSNMP_ALWAYS_DEBUG
#endif

#ifdef NETSNMP_USE_REVERSE_ASNENCODING
# define USE_REVERSE_ASNENCODING NETSNMP_USE_REVERSE_ASNENCODING
#endif
#ifdef NETSNMP_DEFAULT_ASNENCODING_DIRECTION
# define DEFAULT_ASNENCODING_DIRECTION NETSNMP_DEFAULT_ASNENCODING_DIRECTION
#endif

#define PERSISTENT_DIRECTORY NETSNMP_PERSISTENT_DIRECTORY
#define PERSISTENT_MASK NETSNMP_PERSISTENT_MASK
#define AGENT_DIRECTORY_MODE NETSNMP_AGENT_DIRECTORY_MODE
#define MAX_PERSISTENT_BACKUPS NETSNMP_MAX_PERSISTENT_BACKUPS
#define SYSTEM_INCLUDE_FILE NETSNMP_SYSTEM_INCLUDE_FILE
#define MACHINE_INCLUDE_FILE NETSNMP_MACHINE_INCLUDE_FILE

#ifdef NETSNMP_DEFAULT_SERVER_SEND_BUF
# define DEFAULT_SERVER_SEND_BUF NETSNMP_DEFAULT_SERVER_SEND_BUF
#endif
#ifdef NETSNMP_DEFAULT_SERVER_RECV_BUF
# define DEFAULT_SERVER_RECV_BUF NETSNMP_DEFAULT_SERVER_RECV_BUF
#endif
#ifdef NETSNMP_DEFAULT_CLIENT_SEND_BUF
# define DEFAULT_CLIENT_SEND_BUF NETSNMP_DEFAULT_CLIENT_SEND_BUF
#endif
#ifdef NETSNMP_DEFAULT_CLIENT_RECV_BUF
# define DEFAULT_CLIENT_RECV_BUF NETSNMP_DEFAULT_CLIENT_RECV_BUF
#endif

#ifdef NETSNMP_LOGFILE
# define LOGFILE NETSNMP_LOGFILE
#endif

#ifdef NETSNMP_SYS_CONTACT
# define SYS_CONTACT NETSNMP_SYS_CONTACT
#endif

#ifdef NETSNMP_SYS_LOC
# define SYS_LOC NETSNMP_SYS_LOC
#endif

#ifdef NETSNMP_USE_LIBWRAP
# define USE_LIBWRAP NETSNMP_USE_LIBWRAP
#endif

#ifdef NETSNMP_ENABLE_TESTING_CODE 
# define SNMP_TESTING_CODE NETSNMP_ENABLE_TESTING_CODE
#endif

#ifdef NETSNMP_NO_ROOT_ACCESS
# define NO_ROOT_ACCESS NETSNMP_NO_ROOT_ACCESS
#endif

#ifdef NETSNMP_NO_KMEM_USAGE
# define NO_KMEM_USAGE NETSNMP_NO_KMEM_USAGE
#endif

#ifdef NETSNMP_NO_DUMMY_VALUES
# define NO_DUMMY_VALUES NETSNMP_NO_DUMMY_VALUES
#endif

#define VERS_DESC     NETSNMP_VERS_DESC
#define SYS_NAME      NETSNMP_SYS_NAME

#define PROCMIBNUM    NETSNMP_PROCMIBNUM
#define SHELLMIBNUM   NETSNMP_SHELLMIBNUM
#define MEMMIBNUM     NETSNMP_MEMMIBNUM
#define DISKMIBNUM    NETSNMP_DISKMIBNUM

#define LOADAVEMIBNUM NETSNMP_LOADAVEMIBNUM
#define VERSIONMIBNUM NETSNMP_VERSIONMIBNUM
#define ERRORMIBNUM   NETSNMP_ERRORMIBNUM
#define AGENTID       NETSNMP_AGENTID

#define HPUX9ID       NETSNMP_HPUX9ID
#define SUNOS4ID      NETSNMP_SUNOS4ID
#define SOLARISID     NETSNMP_SOLARISID
#define OSFID         NETSNMP_OSFID
#define ULTRIXID      NETSNMP_ULTRIXID
#define HPUX10ID      NETSNMP_HPUX10ID
#define NETBSD1ID     NETSNMP_NETBSD1ID
#define FREEBSDID     NETSNMP_FREEBSDID
#define IRIXID        NETSNMP_IRIXID
#define LINUXID       NETSNMP_LINUXID
#define BSDIID        NETSNMP_BSDIID
#define OPENBSDID     NETSNMP_OPENBSDID
#define WIN32ID       NETSNMP_WIN32ID
#define HPUX11ID      NETSNMP_HPUX11ID
#define AIXID         NETSNMP_AIXID
#define MACOSXID      NETSNMP_MACOSXID
#define UNKNOWNID     NETSNMP_UNKNOWNID

#define ENTERPRISE_OID            NETSNMP_ENTERPRISE_OID
#define ENTERPRISE_MIB            NETSNMP_ENTERPRISE_MIB
#define ENTERPRISE_DOT_MIB        NETSNMP_ENTERPRISE_DOT_MIB
#define ENTERPRISE_DOT_MIB_LENGTH NETSNMP_ENTERPRISE_DOT_MIB_LENGTH

#define SYSTEM_MIB		  NETSNMP_SYSTEM_MIB
#define SYSTEM_DOT_MIB		  NETSNMP_SYSTEM_DOT_MIB
#define SYSTEM_DOT_MIB_LENGTH	  NETSNMP_SYSTEM_DOT_MIB_LENGTH

#define NOTIFICATION_MIB	    NETSNMP_NOTIFICATION_MIB	
#define NOTIFICATION_DOT_MIB	    NETSNMP_NOTIFICATION_DOT_MIB
#define NOTIFICATION_DOT_MIB_LENGTH NETSNMP_NOTIFICATION_DOT_MIB_LENGTH

#define UCDAVIS_OID		  NETSNMP_UCDAVIS_OID
#define UCDAVIS_MIB		  NETSNMP_UCDAVIS_MIB
#define UCDAVIS_DOT_MIB		  NETSNMP_UCDAVIS_DOT_MIB
#define UCDAVIS_DOT_MIB_LENGTH	  NETSNMP_UCDAVIS_DOT_MIB_LENGTH

#define ERRORTIMELENGTH NETSNMP_ERRORTIMELENGTH

#ifdef NETSNMP_PROCFIXCMD
# define PROCFIXCMD NETSNMP_PROCFIXCMD
#endif

#ifdef NETSNMP_EXECFIXCMD
# define EXECFIXCMD NETSNMP_EXECFIXCMD
#endif

#define EXCACHETIME  NETSNMP_EXCACHETIME
#define CACHEFILE    NETSNMP_CACHEFILE
#define MAXCACHESIZE NETSNMP_MAXCACHESIZE

#define DEFDISKMINIMUMSPACE NETSNMP_DEFDISKMINIMUMSPACE
#define DEFMAXLOADAVE NETSNMP_DEFMAXLOADAVE
#define MAXREADCOUNT NETSNMP_MAXREADCOUNT

#define SNMPBLOCK NETSNMP_SNMPBLOCK
#define RESTARTSLEEP NETSNMP_RESTARTSLEEP

#define NUM_COMMUNITIES	NETSNMP_NUM_COMMUNITIES

#ifdef NETSNMP_NO_ZEROLENGTH_COMMUNITY
# define NO_ZEROLENGTH_COMMUNITY NETSNMP_NO_ZEROLENGTH_COMMUNITY
#endif

#define LASTFIELD NETSNMP_LASTFIELD

#define CONFIGURE_OPTIONS NETSNMP_CONFIGURE_OPTIONS

#ifdef NETSNMP_TRANSPORT_UDP_DOMAIN
# define SNMP_TRANSPORT_UDP_DOMAIN NETSNMP_TRANSPORT_UDP_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_CALLBACK_DOMAIN
# define SNMP_TRANSPORT_CALLBACK_DOMAIN NETSNMP_TRANSPORT_CALLBACK_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_TCP_DOMAIN
# define SNMP_TRANSPORT_TCP_DOMAIN NETSNMP_TRANSPORT_TCP_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_UNIX_DOMAIN
# define SNMP_TRANSPORT_UNIX_DOMAIN NETSNMP_TRANSPORT_UNIX_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_AAL5PVC_DOMAIN
# define SNMP_TRANSPORT_AAL5PVC_DOMAIN NETSNMP_TRANSPORT_AAL5PVC_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_IPX_DOMAIN
# define SNMP_TRANSPORT_IPX_DOMAIN NETSNMP_TRANSPORT_IPX_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_UDPIPV6_DOMAIN
# define SNMP_TRANSPORT_UDPIPV6_DOMAIN NETSNMP_TRANSPORT_UDPIPV6_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_TCPIPV6_DOMAIN
# define SNMP_TRANSPORT_TCPIPV6_DOMAIN NETSNMP_TRANSPORT_TCPIPV6_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_TLS_DOMAIN
# define SNMP_TRANSPORT_TLS_DOMAIN NETSNMP_TRANSPORT_TLS_DOMAIN
#endif

#ifdef NETSNMP_TRANSPORT_STD_DOMAIN
# define SNMP_TRANSPORT_STD_DOMAIN NETSNMP_TRANSPORT_STD_DOMAIN
#endif

#ifdef NETSNMP_SECMOD_USM
# define SNMP_SECMOD_USM NETSNMP_SECMOD_USM
#endif

#ifdef NETSNMP_SECMOD_KSM
# define SNMP_SECMOD_KSM NETSNMP_SECMOD_KSM
#endif

#ifdef NETSNMP_SECMOD_LOCALSM 
# define SNMP_SECMOD_LOCALSM NETSNMP_SECMOD_LOCALSM
#endif

#ifdef NETSNMP_REENTRANT
# define NS_REENTRANT NETSNMP_REENTRANT
#endif

#ifdef NETSNMP_ENABLE_IPV6
# define INET6 NETSNMP_ENABLE_IPV6
#endif

#ifdef NETSNMP_ENABLE_LOCAL_SMUX
# define LOCAL_SMUX NETSNMP_ENABLE_LOCAL_SMUX
#endif

#ifdef NETSNMP_AGENTX_DOM_SOCK_ONLY
# define AGENTX_DOM_SOCK_ONLY NETSNMP_AGENTX_DOM_SOCK_ONLY
#endif

#ifdef NETSNMP_SNMPTRAPD_DISABLE_AGENTX
# define SNMPTRAPD_DISABLE_AGENTX
#endif

#ifdef NETSNMP_USE_KERBEROS_MIT
# define MIT_NEW_CRYPTO NETSNMP_USE_KERBEROS_MIT
#endif

#ifdef NETSNMP_USE_KERBEROS_HEIMDAL
# define HEIMDAL NETSNMP_USE_KERBEROS_HEIMDAL
#endif

#ifdef NETSNMP_AGENTX_SOCKET
# define AGENTX_SOCKET NETSNMP_AGENTX_SOCKET
#endif

#ifdef NETSNMP_DISABLE_MIB_LOADING
# define DISABLE_MIB_LOADING NETSNMP_DISABLE_MIB_LOADING
#endif

#ifdef NETSNMP_DISABLE_SNMPV1
# define DISABLE_SNMPV1 NETSNMP_DISABLE_SNMPV1
#endif

#ifdef NETSNMP_DISABLE_SNMPV2C
# define DISABLE_SNMPV2C NETSNMP_DISABLE_SNMPV2C
#endif

#ifdef NETSNMP_DISABLE_SET_SUPPORT
# define DISABLE_SET_SUPPORT NETSNMP_DISABLE_SET_SUPPORT
#endif

#ifdef NETSNMP_DISABLE_DES
# define DISABLE_DES NETSNMP_DISABLE_DES
#endif

#ifdef NETSNMP_DISABLE_MD5
# define DISABLE_MD5 NETSNMP_DISABLE_MD5
#endif

#ifdef NETSNMP_DONT_USE_NLIST
# define DONT_USE_NLIST NETSNMP_DONT_USE_NLIST
#endif

#ifdef NETSNMP_CAN_USE_NLIST
# define CAN_USE_NLIST NETSNMP_CAN_USE_NLIST
#endif

#ifdef NETSNMP_CAN_USE_SYSCTL
# define CAN_USE_SYSCTL NETSNMP_CAN_USE_SYSCTL
#endif

#endif /* NETSNMP_NO_LEGACY_DEFINITIONS */


#endif /* NET_SNMP_CONFIG_H */

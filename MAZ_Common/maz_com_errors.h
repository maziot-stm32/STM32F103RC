/*
 * maz_com_errors.h
 *
 *  Created on: Dec 27, 2019
 *      Author: Paul@maziot.com
 */

#ifndef MAZ_COM_ERRORS_H_
#define MAZ_COM_ERRORS_H_

/* No errors */
#define MAZRET_NOERR        0

/* Compatible with the Linux kernel */
#define MAZRET_EPERM        1       /* Operation not permitted */
#define MAZRET_ENOENT       2       /* No such file or directory */
#define MAZRET_ESRCH        3       /* No such process */
#define MAZRET_EINTR        4       /* Interrupted system call */
#define MAZRET_EIO          5       /* I/O error */
#define MAZRET_ENXIO        6       /* No such device or address */
#define MAZRET_E2BIG        7       /* Argument list too long */
#define MAZRET_ENOEXEC      8       /* Exec format error */
#define MAZRET_EBADF        9       /* Bad file number */
#define MAZRET_ECHILD       10      /* No child processes */
#define MAZRET_EAGAIN       11      /* Try again */
#define MAZRET_ENOMEM       12      /* Out of memory */
#define MAZRET_EACCES       13      /* Permission denied */
#define MAZRET_EFAULT       14      /* Bad address */
#define MAZRET_ENOTBLK      15      /* Block device required */
#define MAZRET_EBUSY        16      /* Device or resource busy */
#define MAZRET_EEXIST       17      /* File exists */
#define MAZRET_EXDEV        18      /* Cross-device link */
#define MAZRET_ENODEV       19      /* No such device */
#define MAZRET_ENOTDIR      20      /* Not a directory */
#define MAZRET_EISDIR       21      /* Is a directory */
#define MAZRET_EINVAL       22      /* Invalid argument */
#define MAZRET_ENFILE       23      /* File table overflow */
#define MAZRET_EMFILE       24      /* Too many open files */
#define MAZRET_ENOTTY       25      /* Not a typewriter */
#define MAZRET_ETXTBSY      26      /* Text file busy */
#define MAZRET_EFBIG        27      /* File too large */
#define MAZRET_ENOSPC       28      /* No space left on device */
#define MAZRET_ESPIPE       29      /* Illegal seek */
#define MAZRET_EROFS        30      /* Read-only file system */
#define MAZRET_EMLINK       31      /* Too many links */
#define MAZRET_EPIPE        32      /* Broken pipe */
#define MAZRET_EDOM         33      /* Math argument out of domain of func */
#define MAZRET_ERANGE       34      /* Math result not representable */

/* Maziot custom return value */
#define MAZRET_ETSKCREATE   35      /* Task create failed */

#endif /* MAZ_COM_ERRORS_H_ */

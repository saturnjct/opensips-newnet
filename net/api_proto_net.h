/*
 * Copyright (C) 2015 OpenSIPS Project
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *
 * history:
 * ---------
 *  2015-01-xx  created (razvanc)
 */

#ifndef _API_PROTO_NET_H_
#define _API_PROTO_NET_H_

#include "tcp_conn_defs.h"

/* api_proto_net flags */
#define PROTO_NET_USE_TCP	(1<<0) /* set by proto's that are based on TCP */
#define PROTO_NET_USE_UDP	(1<<1) /* set by proto's that are based on UDP */


typedef int (*proto_net_write_f)(void *src);
typedef int (*proto_net_read_f)(void *src, int *len);
typedef int (*proto_net_conn_init_f)(struct tcp_connection *c);
typedef void (*proto_net_conn_clean_f)(struct tcp_connection *c);

struct api_proto_net {
	int						id;
	int						flags;
	proto_net_write_f		write;
	proto_net_read_f		read;
	proto_net_conn_init_f	conn_init;
	proto_net_conn_clean_f	conn_clean;
};

#endif /*_API_PROTO_NET_H_ */

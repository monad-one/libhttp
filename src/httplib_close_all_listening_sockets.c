/* 
 * Copyright (c) 2016 Lammert Bies
 * Copyright (c) 2013-2016 the Civetweb developers
 * Copyright (c) 2004-2013 Sergey Lyubka
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * ============
 * Release: 2.0
 */

#include "httplib_main.h"
#include "httplib_memory.h"

/*
 * void XX_httplib_close_all_listening_sockets( struct httplib_context *ctx );
 *
 * The function XX_httplib_close_all_listening_sockets() closes all listening
 * sockets of a given context.
 */

void XX_httplib_close_all_listening_sockets( struct httplib_context *ctx ) {

	unsigned int i;

	if ( ctx == NULL ) return;

	for (i=0; i<ctx->num_listening_sockets; i++) {

		closesocket( ctx->listening_sockets[i].sock );
		ctx->listening_sockets[i].sock = INVALID_SOCKET;
	}

	httplib_free( ctx->listening_sockets    );
	httplib_free( ctx->listening_socket_fds );

	ctx->listening_sockets    = NULL;
	ctx->listening_socket_fds = NULL;

}  /* XX_close_all_listening_sockets */

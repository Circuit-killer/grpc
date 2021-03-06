/*
 *
 * Copyright 2017 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRPC_CORE_LIB_IOMGR_LOCKFREE_EVENT_H
#define GRPC_CORE_LIB_IOMGR_LOCKFREE_EVENT_H

/* Lock free event notification for file descriptors */

#include <grpc/support/atm.h>

#include "src/core/lib/iomgr/exec_ctx.h"

#ifdef __cplusplus
extern "C" {
#endif

void grpc_lfev_init(gpr_atm* state);
void grpc_lfev_destroy(gpr_atm* state);
bool grpc_lfev_is_shutdown(gpr_atm* state);

void grpc_lfev_notify_on(grpc_exec_ctx* exec_ctx, gpr_atm* state,
                         grpc_closure* closure, const char* variable);
/* Returns true on first successful shutdown */
bool grpc_lfev_set_shutdown(grpc_exec_ctx* exec_ctx, gpr_atm* state,
                            grpc_error* shutdown_err);
void grpc_lfev_set_ready(grpc_exec_ctx* exec_ctx, gpr_atm* state,
                         const char* variable);

#ifdef __cplusplus
}
#endif

#endif /* GRPC_CORE_LIB_IOMGR_LOCKFREE_EVENT_H */

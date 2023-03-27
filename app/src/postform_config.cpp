#include <zephyr/sys_clock.h>

#include "postform/config.h"

namespace Postform {
uint64_t getGlobalTimestamp() { return sys_clock_tick_get(); }
}  // namespace Postform

DECLARE_POSTFORM_CONFIG(.timestamp_frequency = CONFIG_SYS_CLOCK_TICKS_PER_SEC);

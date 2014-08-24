/*
 * LED SATA-Disk Activity Trigger
 *
 * Derived from ledtrig-ide-disk.c, below notes are from there.
 *
 * Copyright 2006 Openedhand Ltd.
 *
 * Author: Richard Purdie <rpurdie@openedhand.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/leds.h>

#define BLINK_DELAY 30

DEFINE_LED_TRIGGER(ledtrig_sata);
static unsigned long sata_blink_delay = BLINK_DELAY;

void ledtrig_sata_activity(void)
{
	led_trigger_blink_oneshot(ledtrig_sata,
				  &sata_blink_delay, &sata_blink_delay, 0);
}
EXPORT_SYMBOL(ledtrig_sata_activity);

static int __init ledtrig_sata_init(void)
{
	led_trigger_register_simple("sata-disk", &ledtrig_sata);
	return 0;
}

static void __exit ledtrig_sata_exit(void)
{
	led_trigger_unregister_simple(ledtrig_sata);
}

module_init(ledtrig_sata_init);
module_exit(ledtrig_sata_exit);

MODULE_AUTHOR("Richard Purdie <rpurdie@openedhand.com>");
MODULE_DESCRIPTION("LED SATA Disk Activity Trigger");
MODULE_LICENSE("GPL");

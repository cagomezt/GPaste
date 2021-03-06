/*
 * This file is part of GPaste.
 *
 * Copyright (c) 2010-2016, Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
 */

#if !defined (__G_PASTE_H_INSIDE__) && !defined (G_PASTE_COMPILATION)
#error "Only <gpaste.h> can be included directly."
#endif

#ifndef __G_PASTE_CLIPBOARD_H__
#define __G_PASTE_CLIPBOARD_H__

#include <gpaste-history.h>

G_BEGIN_DECLS

#define G_PASTE_TYPE_CLIPBOARD (g_paste_clipboard_get_type ())

G_PASTE_FINAL_TYPE (Clipboard, clipboard, CLIPBOARD, GObject)

#define g_paste_clipboard_copy_files_target gdk_atom_intern_static_string ("x-special/gnome-copied-files")

typedef void (*GPasteClipboardTextCallback) (GPasteClipboard *self,
                                             const gchar     *text,
                                             gpointer         user_data);

typedef void (*GPasteClipboardImageCallback) (GPasteClipboard *self,
                                              GdkPixbuf       *image,
                                              gpointer         user_data);

void          g_paste_clipboard_bootstrap   (GPasteClipboard *self,
                                             GPasteHistory   *history);
GdkAtom       g_paste_clipboard_get_target  (const GPasteClipboard *self);
GtkClipboard *g_paste_clipboard_get_real    (const GPasteClipboard *self);
const gchar  *g_paste_clipboard_get_text    (const GPasteClipboard *self);
void          g_paste_clipboard_set_text    (GPasteClipboard            *self,
                                             GPasteClipboardTextCallback callback,
                                             gpointer                    user_data);
void          g_paste_clipboard_select_text (GPasteClipboard *self,
                                             const gchar     *text);
void          g_paste_clipboard_clear       (GPasteClipboard *self);
const gchar  *g_paste_clipboard_get_image_checksum (const GPasteClipboard *self);
void          g_paste_clipboard_set_image          (GPasteClipboard             *self,
                                                    GPasteClipboardImageCallback callback,
                                                    gpointer                     user_data);
void          g_paste_clipboard_select_item        (GPasteClipboard *self,
                                                    GPasteItem      *item);
void          g_paste_clipboard_ensure_not_empty   (GPasteClipboard     *self,
                                                    const GPasteHistory *history);

GPasteClipboard *g_paste_clipboard_new (GdkAtom         target,
                                        GPasteSettings *settings);

G_END_DECLS

#endif /*__G_PASTE_CLIPBOARD_H__*/

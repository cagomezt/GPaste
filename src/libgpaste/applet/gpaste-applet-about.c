/*
 * This file is part of GPaste.
 *
 * Copyright (c) 2010-2016, Marc-Antoine Perennou <Marc-Antoine@Perennou.com>
 */

#include <gpaste-applet-about.h>

struct _GPasteAppletAbout
{
    GtkMenuItem parent_instance;
};

typedef struct
{
    GPasteClient *client;
} GPasteAppletAboutPrivate;

G_PASTE_DEFINE_TYPE_WITH_PRIVATE (AppletAbout, applet_about, GTK_TYPE_MENU_ITEM)

static void
g_paste_applet_about_activate (GtkMenuItem *menu_item)
{
    const GPasteAppletAboutPrivate *priv = _g_paste_applet_about_get_instance_private (G_PASTE_APPLET_ABOUT (menu_item));

    g_paste_client_about (priv->client, NULL, NULL);

    GTK_MENU_ITEM_CLASS (g_paste_applet_about_parent_class)->activate (menu_item);
}

static void
g_paste_applet_about_dispose (GObject *object)
{
    const GPasteAppletAboutPrivate *priv = _g_paste_applet_about_get_instance_private (G_PASTE_APPLET_ABOUT (object));

    g_clear_object (&priv->client);

    G_OBJECT_CLASS (g_paste_applet_about_parent_class)->dispose (object);
}

static void
g_paste_applet_about_class_init (GPasteAppletAboutClass *klass)
{
    G_OBJECT_CLASS (klass)->dispose = g_paste_applet_about_dispose;
    GTK_MENU_ITEM_CLASS (klass)->activate = g_paste_applet_about_activate;
}

static void
g_paste_applet_about_init (GPasteAppletAbout *self G_GNUC_UNUSED)
{
}

/**
 * g_paste_applet_about_new:
 * @client: a #GPasteClient instance
 *
 * Create a new instance of #GPasteAppletAbout
 *
 * Returns: a newly allocated #GPasteAppletAbout
 *          free it with g_object_unref
 */
G_PASTE_VISIBLE GtkWidget *
g_paste_applet_about_new (GPasteClient *client)
{
    g_return_val_if_fail (_G_PASTE_IS_CLIENT (client), NULL);

    GtkWidget *self = gtk_widget_new (G_PASTE_TYPE_APPLET_ABOUT,
                                      "label", _("About"),
                                      NULL);
    GPasteAppletAboutPrivate *priv = g_paste_applet_about_get_instance_private (G_PASTE_APPLET_ABOUT (self));

    priv->client = g_object_ref (client);

    return self;
}

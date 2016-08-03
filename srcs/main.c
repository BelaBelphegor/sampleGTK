/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:03 by tiboitel          #+#    #+#             */
/*   Updated: 2016/08/03 18:23:49 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <gtk/gtk.h>
#include <stdio.h>

static void	gtk_ondestroy(GtkWidget *pwidget, gpointer pdata)
{
	(void)pwidget;
	(void)pdata;
	gtk_main_quit();
	exit(1);
}

int			main(int argc, char **argv)
{
	GtkWidget	*pwindow;
	GtkWidget	*plabel;
	GtkWidget	*pquitbtn;
	gchar		*sutf8;
	/*
	 ** @Initialisation de GTK+3.18
	 */
	gtk_init(&argc, &argv);
	/*
	 ** @Creation de la fenetre.
	 */
	pwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(pwindow), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(pwindow), "Raytracer Interface");
	gtk_window_set_default_size(GTK_WINDOW(pwindow), 420, 680);
	/*
	 ** @Creation et initialisation du label.
	 */
	(void)plabel;
	(void)sutf8;
/*	sutf8 = g_locale_to_utf8("Liste des primitives", -1, NULL, NULL, NULL);
	plabel = gtk_label_new(sutf8);
	g_free(sutf8);
	gtk_container_add(GTK_CONTAINER(pwindow), plabel);
*/	/*
	 ** @Creation et initialisation d'un bouton.
	 */ 
	pquitbtn = gtk_button_new_with_label("Quitter");
	g_signal_connect(G_OBJECT(pquitbtn), "clicked", G_CALLBACK(gtk_ondestroy), NULL);
	gtk_container_add(GTK_CONTAINER(pwindow), pquitbtn);
	/*
	 ** @ Definition du callback pour le signal destroy.
	 */
	g_signal_connect(G_OBJECT(pwindow), "destroy", G_CALLBACK(gtk_ondestroy), NULL);
	/*
	 ** @Affichage de la fenetre et de tout ce qu'il contient.
	 */
	gtk_widget_show_all(pwindow);
	/*
	 ** @Lancement de la boucle evenementielle.
	 */
	gtk_main();
	/*
	 ** Destruction de la fenetre.
	 */
	gtk_widget_destroy(pwindow);
	return (0);
}

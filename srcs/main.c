/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 17:20:03 by tiboitel          #+#    #+#             */
/*   Updated: 2016/08/03 21:55:59 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <gtk/gtk.h>
#include <stdio.h>

static void	gtk_ondestroy(GtkWidget *pwidget, gpointer data)
{
	(void)pwidget;
	(void)data;
	gtk_widget_destroy(pwidget);
	gtk_main_quit();
	exit(1);
}

static void gtk_activate_entry(GtkWidget *pwidget, gpointer data)
{
	const gchar		*text;
	
	text = gtk_entry_get_text(GTK_ENTRY(pwidget));
	gtk_label_set_text(GTK_LABEL((GtkWidget *)data), text);;
}

int			main(int argc, char **argv)
{
	GtkWidget	*pwindow;
	GtkWidget	*plabel;
	GtkWidget	*pquitbtn;
	GtkWidget	*pgrid;
	GtkWidget	*pentry;
	GtkWidget	*pframe;
	GtkWidget	*pseparator;
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
	 ** @Creation de la table.
	 */
	pgrid = gtk_grid_new();
	//gtk_grid_set_row_homogeneous(GTK_GRID(pgrid), TRUE);
	gtk_grid_set_column_spacing(GTK_GRID(pgrid), 5);
	gtk_grid_set_row_spacing(GTK_GRID(pgrid), 10);
	gtk_grid_set_column_homogeneous(GTK_GRID(pgrid), TRUE);
	gtk_container_add(GTK_CONTAINER(pwindow), pgrid);
	/*
	 ** @Frame d'encadrement
	 */
	pframe = gtk_frame_new("Gestion des objets");
	gtk_grid_attach(GTK_GRID(pgrid), pframe, 0, 0, 2, 5);
	/*
	 ** @Creation et ajout du separateur a la grille.
	 */
	pseparator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_grid_attach(GTK_GRID(pgrid), pseparator, 0, 2, 2, 1);
	/*
	 ** @Creation et initialisation du label.
	 */
	(void)plabel;
	(void)sutf8;
	sutf8 = g_locale_to_utf8("Liste des primitives", -1, NULL, NULL, NULL);
	plabel = gtk_label_new(sutf8);
	g_free(sutf8);
	gtk_grid_attach(GTK_GRID(pgrid), plabel, 0, 1, 1, 1);

	/*
	 ** @Creation et initialisation de l'entree texte.
	 */
	pentry = gtk_entry_new();
	g_signal_connect(G_OBJECT(pentry), "activate", G_CALLBACK(gtk_activate_entry), (GtkWidget *)plabel);
	gtk_grid_attach(GTK_GRID(pgrid), pentry, 1, 1, 1, 1);
	/*
	 ** @Creation et initialisation d'un bouton.
	 */ 
	pquitbtn = gtk_button_new_with_label("Quitter");
	g_signal_connect(G_OBJECT(pquitbtn), "clicked", G_CALLBACK(gtk_ondestroy), NULL);
	gtk_grid_attach(GTK_GRID(pgrid), pquitbtn, 0, 3, 2, 1);
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

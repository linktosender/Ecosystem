#pragma once
#ifndef Q_ARROW_ITEM
#define Q_ARROW_ITEM


#include <QGraphicsItem>
#include <QBrush>


class celluleHumaine : public QGraphicsItem
{
public:
	// On choisi un constructeur par d�faut offrant optionnellement un acc�s � tous les param�tres de la forme.
	celluleHumaine(double lifeExpectancy = 1.0, QPointF const& initialPosition = QPointF(), qreal initialOrientationDegrees = 0.0, qreal initialSpeed = 1.0, qreal scale = 1.0, QBrush const& brush = Qt::white, QGraphicsItem* parent = nullptr);
	~celluleHumaine() override = default;
	celluleHumaine(celluleHumaine const&) = default;
	celluleHumaine& operator=(celluleHumaine const&) = delete;

	// Mutateur de couleur et de vitesse
	QBrush getColor();
	qreal getSpeed();
	void setColor(QBrush const& brush);
	void setSpeed(qreal speed);

	// Fonction abstraite de QGraphicsItem (DOIT �tre "override") : retourne la taille de l'item
	QRectF boundingRect() const override;
	// Fonction abstraite de QGraphicsItem (DOIT �tre "override") : dessine la forme
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

	// Fonction virtuelle de QGraphicsItem (peut �tre "override") : fait un tick de simulation
	void advance(int phase) override;

	bool isAlive() const;

	void splitCellule();

protected:
	// L'esp�rance de vie et l'�ge
	double mLifeExpectancy;
	double mAge;
	// La couleur de fond
	QBrush mBrush;
	// La forme 
	QPolygonF mShape;
	// La vitesse
	qreal mSpeed;

	// 
	QPointF mNewPosition;
	qreal mNewOrientation;

	// Fonctions math�matiques utilitaires servant � r�aliser la "t�l�portation".
	// Id�alement, devraient �tre dans une autre classe utilitaire de calcul.
	static qreal warp(qreal value, qreal begin, qreal end);
	void warp(QPointF& point);
};

#endif // Q_ARROW_ITEM_H

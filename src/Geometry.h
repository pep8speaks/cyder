/** \file Geometry.h
 * \brief Declares the Geometry class for defining the cylindrical extent and 
 * position of the component
 * \author Kathryn D. Huff
 */
#if !defined(_GEOMETRY_H)
#define (_GEOMETRY_H)

/// type definition for Radius in meters
typedef double Radius;

/// Enum for type of boundary.
enum BoundaryType {INNER, OUTER};

/// type definition for an X, Y, Z point definition
typedef struct point_t{
  double x_; /**<The x coordinate of the centroid */
  double y_; /**<The y coordinate of the centroid */
  double z_; /**<The z coordinate of the centroid */
}point_t;

/**
   @brief The Geometry class stores the cylindrical Component geometry 

   The Geometry class holds information about the position, extent, and 
   structure of the component geometry.
 */
class Geometry {
  
public:
  /**
     Set the radius of the surface at the boundary indicated. 
     inner radius is 0 for solid objects. [m]
     outer radius is null for infinite objects. [m]

     @param boundary the boundary at which to set the radius
     @param radius the new radius at the boundary [m]
    */
  void set_radius(BoundaryType boundary, Radius radius); 

  /**
     Set the coordinate location of the centroid, a point. [m]

     @param centroid the central point of the cylinder
    */
  void set_centroid(point_t centroid); 

  /**
     Radius of the inner surface. 0 for solid objects. [m]
    */
  Radius inner_radius(); 

  /**
     Returns the radius of the outer surface. NULL for infinite objects.[m] 
    */
  Radius outer_radius(); 

  /**
     Returns the coordinate location of the centroid, a point. [m]
    */
  point_t centroid(); 

  /// get the x component of the centroid position vector of the object
  const double x();

  /// get the y component of the centroid position vector of the object
  const double y();

  /// get the z component of the centroid position vector of the object
  const double z();

protected:
  /**
     Radius of the inner surface. 0 for solid objects. [m]
    */
  Radius inner_radius_; 

  /**
     Radius of the outer surface. NULL for infinite objects. [m]
    */
  Radius outer_radius_; 

  /**
     The coordinate location of the centroid, a point. [m]
    */
  point_t centroid_; 

};


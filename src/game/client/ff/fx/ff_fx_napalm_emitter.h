//========= FF Grenade Port ===============================================//
//
// Ported from ff-src/mp/src/game/client/ff/fx/ff_fx_napalm_emitter.h
// (original: FF, Shawn Smith "L0ki", Apr. 30 2005). This is the real
// napalm burst/ground-fire particle system -- classic FF's actual visual
// for napalm, as opposed to the generic CEntityFlame-driven glow each
// napalmlet gib also has (ff_grenade_napalmlet.cpp, unrelated/untouched).
//
// See ff_fx_napalm_emitter.cpp for what's ported verbatim vs. changed.
//
//===========================================================================//

#ifndef FF_FX_NAPALM_EMITTER_H
#define FF_FX_NAPALM_EMITTER_H

enum NapalmParticleType
{
	eNapalmParticle,
	eNapalmFlame,
	eHeatwave
};

class NapalmParticle : public Particle
{
public:
	NapalmParticle() {}

	NapalmParticleType m_iType;
	Vector			m_vVelocity;
	float			m_flDieTime;
	float			m_flLifetime;
	unsigned char	m_uchColor[4];
	bool			m_bStartFire;
	bool			m_bReverseSize;
	float			m_flScale;

	// FF Grenade Port: added for gib-attached flames (napalmlet). When valid,
	// SimulateParticles() repositions this particle to the entity's current
	// position every frame instead of doing ballistic/ground-collision
	// simulation, and removes the particle the instant the entity is gone --
	// no fixed timer needed, the flame's lifetime is tied to the gib's actual
	// lifetime. Not in FF's real source (that used CEntityFlame for this,
	// which we can't get a working visual out of -- see ff_grenade_napalmlet.cpp
	// for the full explanation of why this exists instead).
	EHANDLE			m_hFollowEntity;
	bool			m_bIsAttachedFlame;
};

class CNapalmEmitter : public CParticleEffect
{
public:
	DECLARE_CLASS( CNapalmEmitter, CParticleEffect );

	static CSmartPtr<CNapalmEmitter> Create( const char *pDebugName );

	virtual void SimulateParticles	( CParticleSimulateIterator *pIterator );
	virtual void RenderParticles	( CParticleRenderIterator *pIterator );

	NapalmParticle*	AddNapalmParticle( const Vector &vOrigin);

			void	SetGravity(const Vector &vGravity, float flGravityMagnitude);
	inline	Vector	GetGravity(void) { return m_vGravity; }
	inline	float	GetGravityMagnitude(void) { return m_flGravityMagnitude; }
	
	void StartFire(const Vector &pos);

	// FF Grenade Port: creates a flame that follows pFollowEntity every frame
	// instead of sitting at a fixed position -- see NapalmParticle::m_hFollowEntity.
	void StartAttachedFire( CBaseEntity *pFollowEntity );

protected:
	CNapalmEmitter( const char *pDebugName );
	virtual			~CNapalmEmitter();

private:
	CNapalmEmitter( const CNapalmEmitter & );

	void ApplyGravity(NapalmParticle *pParticle, float flTimeDelta);

	float m_flNearClipMin;
	float m_flNearClipMax;
	Vector m_vGravity;
	float m_flGravityMagnitude;

	static PMaterialHandle m_hMaterial;
	static PMaterialHandle m_hFlameMaterial;
	// FF Grenade Port: FF's real m_hHeatwaveMaterial dropped -- the only code that
	// used it (a second particle spawned alongside each flame, for a heat-shimmer
	// look) is entirely commented out in FF's own real source, and the material
	// it would need (sprites/heatwave) has a .vtf in ff-game but no matching .vmt,
	// so precaching it would just be a guaranteed "material not found" warning for
	// a particle that never actually spawns. Not a placeholder -- the real code
	// never used it either, this just doesn't carry along a precache for
	// genuinely dead code.
};

// Render a quad on the screen where you pass in color and size.
// Normal is random and "flutters"
inline void RenderParticle_ColorSizePerturbNormal(
	ParticleDraw* pDraw,									
	const Vector &pos,
	const Vector &color,
	const float alpha,
	const float size
	)
{
	// Don't render totally transparent particles.
	if( alpha < 0.001f )
		return;

	CMeshBuilder *pBuilder = pDraw->GetMeshBuilder();
	if( !pBuilder )
		return;

	unsigned char ubColor[4];
	ubColor[0] = (unsigned char)RoundFloatToInt( color.x * 254.9f );
	ubColor[1] = (unsigned char)RoundFloatToInt( color.y * 254.9f );
	ubColor[2] = (unsigned char)RoundFloatToInt( color.z * 254.9f );
	ubColor[3] = (unsigned char)RoundFloatToInt( alpha * 254.9f );

	Vector vNorm;

	vNorm.Random( -1.0f, 1.0f );

	// Add the 4 corner vertices.
	pBuilder->Position3f( pos.x-size, pos.y-size, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->Normal3fv( vNorm.Base() );
	pBuilder->TexCoord2f( 0, 0, 1.0f );
	pBuilder->AdvanceVertex();

	pBuilder->Position3f( pos.x-size, pos.y+size, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->Normal3fv( vNorm.Base() );
	pBuilder->TexCoord2f( 0, 0, 0 );
	pBuilder->AdvanceVertex();

	pBuilder->Position3f( pos.x+size, pos.y+size, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->Normal3fv( vNorm.Base() );
	pBuilder->TexCoord2f( 0, 1.0f, 0 );
	pBuilder->AdvanceVertex();

	pBuilder->Position3f( pos.x+size, pos.y-size, pos.z );
	pBuilder->Color4ubv( ubColor );
	pBuilder->Normal3fv( vNorm.Base() );
	pBuilder->TexCoord2f( 0, 1.0f, 1.0f );
	pBuilder->AdvanceVertex();
}

#endif//FF_FX_NAPALM_EMITTER_H

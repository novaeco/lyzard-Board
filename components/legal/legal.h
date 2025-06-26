#ifndef LEGAL_H
#define LEGAL_H

#ifdef __cplusplus
extern "C" {
#endif

/** Initialise les paramètres liés à la conformité légale. */
void legal_init(void);

/** Génère les documents obligatoires pour une opération. */
void legal_generate_docs(const char *operation);

#ifdef __cplusplus
}
#endif

#endif // LEGAL_H

#ifndef IOHDF5_H
#define IOHDF5_H

#include <hdf5.h>
#include <emc_common.h>
#include <errors.h>
#include <sys/stat.h>


void write_1d_real_array_hdf5(char *filename, real *array, int index1_max);
void write_1d_int_array_hdf5(char *filename, int *array, int index1_max);
hid_t init_scaling_file(char *filename, int N_images, hid_t *file_id);
void write_scaling_to_file(const hid_t dataset, const int iteration, float *scaling, float *respons, int N_slices);
void close_scaling_file(hid_t dataset, hid_t file);
void write_2d_real_array_hdf5(char *filename, real *array, int index1_max, int index2_max);
void write_2d_real_array_hdf5_transpose(char *filename, real *array, int index1_max, int index2_max);
void close_scaling_file(hid_t dataset, hid_t file);
void write_2d_real_array_hdf5(char *filename, real *array, int index1_max, int index2_max);
void write_2d_real_array_hdf5_transpose(char *filename, real *array, int index1_max, int index2_max);

void write_3d_array_hdf5(char *filename, real *array, int index1_max, int index2_max, int index3_max);
sp_matrix **read_images_cxi(const char *filename, const char *image_identifier, const char *mask_identifier,
                            const int number_of_images, const int image_side, const int binning_factor,
                            sp_imatrix **list_of_masks);
sp_matrix **read_images(Configuration conf, sp_imatrix **masks);
sp_imatrix *read_mask(Configuration conf);
void write_run_info(char *filename, Configuration conf, int random_seed);
hid_t open_state_file(char *filename);
void write_state_file_iteration(hid_t file_id, int iteration);
void close_state_file(hid_t file_id);
int read_rotations_file(const char *filename, Quaternion **rotations, real **weights);
void mkdir_recursive(const char *dir, int permission);


#endif